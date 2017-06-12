#include "material.h"

Material::Material(const Color &color, float Ka, float Kd, float Ks, float reflectivity, float shininess) :
    _color(color), _Ka(Ka), _Kd(Kd), _Ks(Ks), _reflectivity(reflectivity), _shininess(shininess)
{

}

float Material::Ka() const
{
    return _Ka;
}

void Material::setKa(float Ka)
{
    _Ka = Ka;
}

float Material::Kd() const
{
    return _Kd;
}

void Material::setKd(float Kd)
{
    _Kd = Kd;
}

float Material::Ks() const
{
    return _Ks;
}

void Material::setKs(float Ks)
{
    _Ks = Ks;
}

float Material::reflectivity() const
{
    return _reflectivity;
}

void Material::setReflectivity(float reflectivity)
{
    _reflectivity = reflectivity;
}

float Material::shininess() const
{
    return _shininess;
}

void Material::setShininess(float shininess)
{
    _shininess = shininess;
}

Color Material::color() const
{
    return _color;
}

void Material::setColor(const Color &color)
{
    _color = color;
}
