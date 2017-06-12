#ifndef PLANE_H
#define PLANE_H

#include "object.h"


class Plane : public Object
{
public:
    Plane(const Material &material, QVector3D center, QVector3D normal);
    virtual ~Plane() {};

    Intersection *intersect(const Ray &ray);

private:
    QVector3D _center;
    QVector3D _normal;
};

#endif // PLANE_H
