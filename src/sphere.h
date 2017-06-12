#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"

class Sphere : public Object
{
public:
    Sphere(const Material &material, QVector3D center, float radius);
    virtual ~Sphere() {};

    Intersection *intersect(const Ray &ray);

private:
    QVector3D _center;
    float _radius;
};

#endif // SPHERE_H
