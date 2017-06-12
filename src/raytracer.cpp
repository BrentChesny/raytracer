#include "raytracer.h"

#include <QtGlobal>
#include <QDebug>

#include <random>
#include <limits>
#include <math.h>

const float RayTracer::EPSILON = 1e-4;

RayTracer::RayTracer()
{
}

QImage RayTracer::render(const Scene &scene, const Camera &camera, int width, int height, int maxDepth)
{
    QImage image(width, height, QImage::Format::Format_RGB888);

    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            int ns = 16;
            int r = 0.0f, g = 0.0f, b = 0.0f;
            for (int s = 0; s < ns; ++s) {
                float dx = (float) rand() / RAND_MAX;
                float dy = (float) rand() / RAND_MAX;

                QVector3D xShift = (x - width/2.0 + dx) / width * camera.getFov() * camera.getRight();
                QVector3D yShift = (y - height/2.0 + dy) / width * camera.getFov() * camera.getUp();

                Ray ray(camera.getPosition(), camera.getLookAt() + xShift + yShift - camera.getPosition());

                QColor color = this->trace(scene, ray, maxDepth, 0);

                r += color.red();
                g += color.green();
                b += color.blue();
            }

            image.setPixelColor(x, height - y - 1, QColor(r/ns, g/ns, b/ns));
        }
    }

    return image;
}

QColor RayTracer::trace(const Scene &scene, const Ray &ray, int maxDepth, int depth)
{
    Intersection* intersection = this->findClosestIntersection(scene, ray);

    if (intersection == nullptr)
        return scene.getAmbient();

    Object* object = intersection->getObject();
    if (depth == maxDepth)
        return object->getColor();

    QColor reflectedColor(0, 0, 0);
    if (object->getReflectivity() > 0.0f) {
        QVector3D reflectedDir = ray.getDirection() - 2 * intersection->getNormal() * QVector3D::dotProduct(ray.getDirection(), intersection->getNormal());
        Ray reflectedRay(intersection->getPoint() + (EPSILON * intersection->getNormal()), reflectedDir);

        reflectedColor = this->trace(scene, reflectedRay, maxDepth, depth+1);
    }

    float brightness = this->diffuseToLights(scene, intersection->getPoint(), intersection->getNormal(), intersection->getObject());

    int r = (int) ((object->getReflectivity() * reflectedColor.red() + (1.0f - object->getReflectivity()) * object->getColor().red()) * brightness);
    int g = (int) ((object->getReflectivity() * reflectedColor.green() + (1.0f - object->getReflectivity()) * object->getColor().green()) * brightness);
    int b = (int) ((object->getReflectivity() * reflectedColor.blue() + (1.0f - object->getReflectivity()) * object->getColor().blue()) * brightness);

    r = qBound(0, 255, r);
    g = qBound(0, 255, g);
    b = qBound(0, 255, b);

    return QColor(r, g, b);
}

Intersection *RayTracer::findClosestIntersection(const Scene &scene, const Ray &ray)
{
    float closestDist = std::numeric_limits<float>::max();
    Intersection* closestIntersection = nullptr;

    foreach (Object* object, scene.getObjects())
    {
        Intersection* intersection = object->intersect(ray);
        if (intersection->isTrueIntersection() && EPSILON < intersection->getDistance() && intersection->getDistance() < closestDist) {
            delete closestIntersection;
            closestIntersection = intersection;
            closestDist = intersection->getDistance();
        } else {
            delete intersection;
        }
    }

    return closestIntersection;
}

float RayTracer::diffuseToLights(const Scene &scene, QVector3D point, QVector3D normal, Object *object)
{
    float brightness = 0.0f;

    foreach(Light* light, scene.getLights())
    {
        QVector3D toLight = light->getPosition() - point;
        Ray ray(point + (EPSILON * normal), toLight);

        if (this->findClosestIntersection(scene, ray) == nullptr) {
            float cosine = fmax(0, QVector3D::dotProduct(toLight, normal) / (toLight.length() * normal.length()));
            float intensity = 100.0f * light->getIntensity() / QVector3D::dotProduct(toLight, toLight);

            brightness += intensity * cosine;

            if (object->getSpecular() > 0.0f)
                brightness += intensity * object->getSpecular() * pow(cosine, object->getSpecularFalloff());
        }
    }

    return brightness + scene.getGamma();
}
