#include "object.h"

Object::Object(QColor color, float reflectivity, float specular, float specularFalloff) :
    _color(color), _reflectivity(reflectivity), _specular(specular), _specularFalloff(specularFalloff)
{
}
