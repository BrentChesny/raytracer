#ifndef LIGHT_H
#define LIGHT_H

#include <QVector3D>

#include "color.h"


class Light
{
public:
    Light(QVector3D position);

    QVector3D getPosition() const { return _position; }
    Color getIntensity() const;

private:
    QVector3D _position;
    Color _intensity;
};

#endif // LIGHT_H
