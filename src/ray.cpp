#include "ray.h"

Ray::Ray(QVector3D origin, QVector3D direction) :
    _origin(origin), _direction(direction.normalized())
{
}
