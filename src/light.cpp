#include "light.h"

Light::Light(const QVector3D &position, const Color &color, float intensity) :
    _position(position), _color(color), _intensity(intensity)
{

}

Color Light::getColor() const
{
    return _color;
}

void Light::setColor(const Color &color)
{
    _color = color;
}

QVector3D Light::getPosition() const
{
    return _position;
}

void Light::setPosition(const QVector3D &position)
{
    _position = position;
}

float Light::getIntensity() const
{
    return _intensity;
}

void Light::setIntensity(float intensity)
{
    _intensity = intensity;
}
