#ifndef PLANE_H
#define PLANE_H

#include "object.h"


class Plane : public Object
{
public:
    Plane(QColor color, float reflectivity, float specular, float specularFalloff, QVector3D center, QVector3D normal);

    Intersection *intersect(const Ray &ray);

private:
    QVector3D _center;
    QVector3D _normal;
};

#endif // PLANE_H
