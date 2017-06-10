#include "intersection.h"

Intersection::Intersection(Object *object, float distance, QVector3D point, QVector3D normal, bool trueIntersection) :
    _object(object), _distance(distance), _point(point), _normal(normal), _trueIntersection(trueIntersection)
{
}
