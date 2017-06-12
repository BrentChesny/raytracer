#include "object.h"

Object::Object(const Material material) :
    _material(material)
{
}

Material Object::material() const
{
    return _material;
}

void Object::setMaterial(const Material &material)
{
    _material = material;
}
