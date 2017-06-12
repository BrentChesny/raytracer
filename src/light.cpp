#include "light.h"

Light::Light(QVector3D position) :
    _position(position), _intensity(Color::WHITE)
{

}

Color Light::getIntensity() const
{
    return _intensity;
}
