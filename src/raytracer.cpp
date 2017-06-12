#include "raytracer.h"

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
            int ns = 4;
            int r = 0.0f, g = 0.0f, b = 0.0f;
            for (int s = 0; s < ns; ++s) {
                float dx = (float) rand() / RAND_MAX;
                float dy = (float) rand() / RAND_MAX;

                QVector3D xShift = (x - width/2.0 + dx) / width * camera.getFov() * camera.getRight();
                QVector3D yShift = (y - height/2.0 + dy) / width * camera.getFov() * camera.getUp();

                Ray ray(camera.getPosition(), camera.getLookAt() + xShift + yShift - camera.getPosition());

                Color color = this->trace(scene, ray, maxDepth, 0);

                r += color.red();
                g += color.green();
                b += color.blue();
            }

            image.setPixelColor(x, height - y - 1, Color(r/ns, g/ns, b/ns));
        }
    }

    return image;
}

Color RayTracer::trace(const Scene &scene, const Ray &ray, int maxDepth, int depth)
{
    Intersection* intersection = this->findClosestIntersection(scene, ray);

    if (intersection == nullptr)
        return scene.getAmbient();

    Object* object = intersection->getObject();
    QVector3D P = intersection->getPoint();
    QVector3D N = intersection->getNormal();

    Material mat = object->material();

    Color color = scene.getAmbient() * mat.Ka();

    foreach(Light* light, scene.getLights())
    {
        QVector3D Lm = (light->getPosition() - P).normalized();
        Ray ray(P + (EPSILON * N), Lm);

        if (this->findClosestIntersection(scene, ray) == nullptr)
        {
            float lambertian = QVector3D::dotProduct(Lm, N);

            color += light->getIntensity() * lambertian * mat.Kd();

            if (lambertian > 0.0f)
            {
                QVector3D Rm = 2.0f * lambertian * N - Lm;
                QVector3D V = (ray.getOrigin() - P).normalized();

                float RmV = QVector3D::dotProduct(Rm, V);

                color += light->getIntensity() * pow(RmV, mat.shininess()) * mat.Ks();
            }
        }
    }

    Color reflectedColor(0, 0, 0);
    if (depth < maxDepth && mat.reflectivity() > 0.0f) {
        QVector3D R = ray.getDirection() - 2 * N * QVector3D::dotProduct(ray.getDirection(), N);
        Ray reflectedRay(P + (EPSILON * N), R);

        reflectedColor = this->trace(scene, reflectedRay, maxDepth, depth+1);
    }

    return mat.color() * (color + reflectedColor * mat.reflectivity());
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
