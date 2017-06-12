#ifndef LIGHT_H
#define LIGHT_H

#include <QVector3D>

#include "color.h"


class Light
{
public:
    Light(const QVector3D &position, const Color &color = Color::WHITE, float intensity = 1.0f);

    Color getColor() const;
    void setColor(const Color &color);

    QVector3D getPosition() const;
    void setPosition(const QVector3D &position);

    float getIntensity() const;
    void setIntensity(float intensity);

private:
    QVector3D _position;
    Color _color;
    float _intensity;
};

#endif // LIGHT_H
