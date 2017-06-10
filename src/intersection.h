#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "object.h"

class Intersection
{
public:
    Intersection(Object* object = nullptr, float distance = 0.0f, QVector3D point = QVector3D(0.0f, 0.0f, 0.0f), QVector3D normal = QVector3D(0.0f, 0.0f, 1.0f), bool trueIntersection = false);

    Object* getObject() const { return _object; }
    float getDistance() const { return _distance; }
    QVector3D getPoint() const { return _point; }
    QVector3D getNormal() const { return _normal; }
    bool isTrueIntersection() const { return _trueIntersection; }

private:
    Object* _object;
    float _distance;
    QVector3D _point;
    QVector3D _normal;
    bool _trueIntersection;
};

#endif // INTERSECTION_H
