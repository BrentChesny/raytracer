#include "plane.h"
#include "intersection.h"

Plane::Plane(QColor color, float reflectivity, float specular, float specularFalloff, QVector3D center, QVector3D normal) :
    Object(color, reflectivity, specular, specularFalloff), _center(center), _normal(normal)
{

}

Intersection *Plane::intersect(const Ray &ray)
{
    float dot = QVector3D::dotProduct(_normal, ray.getDirection());

    if (dot == 0.0f) {
        return new Intersection;
    } else {
        float dist = QVector3D::dotProduct(_center - ray.getOrigin(), _normal) / dot;

        if (dist < 0.0f)
            return new Intersection;

        return new Intersection(this, dist, ray.getOrigin() + dist * ray.getDirection(), _normal, true);
    }
}
