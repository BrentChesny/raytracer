#include "sphere.h"
#include "intersection.h"

#include <math.h>

Sphere::Sphere(QColor color, float reflectivity, float specular, float specularFalloff, QVector3D center, float radius) :
    Object(color, reflectivity, specular, specularFalloff), _center(center), _radius(radius)
{

}

Intersection *Sphere::intersect(const Ray &ray)
{
    QVector3D dir = ray.getDirection();
    QVector3D orig = ray.getOrigin();

    float a = QVector3D::dotProduct(dir, dir);
    float b = 2.0f * QVector3D::dotProduct(dir, orig - _center);
    float c = QVector3D::dotProduct(orig - _center, orig - _center) - pow(_radius, 2);

    float discriminant = b*b - 4*a*c;

    if (discriminant <= 1e-8) {
        return new Intersection;
    } else {
        float dist1 = (-b + sqrt(discriminant)) / (2.0f * a);
        float dist2 = (-b - sqrt(discriminant)) / (2.0f * a);
        float dist;

        if (dist1 <= 1e-8 && dist2 <= 1e-8)
            return new Intersection;
        else if (dist1 <= 1e-8 || dist2 <=  1e-8)
            dist = fmax(dist1, dist2);
        else
            dist = fmin(dist1, dist2);

        QVector3D point = orig + (dir * dist);
        QVector3D normal = (point - _center).normalized();

        return new Intersection(this, dist, point, normal, true);
    }
}
