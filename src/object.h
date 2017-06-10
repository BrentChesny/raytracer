#ifndef OBJECT_H
#define OBJECT_H

#include "ray.h"

#include <QColor>

class Intersection;

class Object
{
public:
    Object(QColor color, float reflectivity, float specular, float specularFalloff);

    virtual Intersection* intersect(const Ray &ray) = 0;

    QColor getColor() const { return _color; }
    float getReflectivity() const { return _reflectivity; }
    float getSpecular() const { return _specular; }
    float getSpecularFalloff() const { return _specularFalloff; }

protected:
    QColor _color;
    float _reflectivity;
    float _specular;
    float _specularFalloff;
};

#endif // OBJECT_H
