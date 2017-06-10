#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"

class Sphere : public Object
{
public:
    Sphere(QColor color, float reflectivity, float specular, float specularFalloff, QVector3D center, float radius);

    Intersection *intersect(const Ray &ray);

private:
    QVector3D _center;
    float _radius;
};

#endif // SPHERE_H
