#ifndef RAY_H
#define RAY_H

#include <QVector3D>



class Ray
{
public:
    Ray(QVector3D origin, QVector3D direction);

    QVector3D getOrigin() const { return _origin; }
    QVector3D getDirection() const { return _direction; }

private:
    QVector3D _origin;
    QVector3D _direction;
};

#endif // RAY_H
