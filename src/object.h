#ifndef OBJECT_H
#define OBJECT_H

#include "material.h"
#include "ray.h"

class Intersection;

class Object
{
public:
    Object(const Material material);
    virtual ~Object() {};

    virtual Intersection* intersect(const Ray &ray) = 0;

    Material material() const;
    void setMaterial(const Material &material);

protected:
    Material _material;
};

#endif // OBJECT_H
