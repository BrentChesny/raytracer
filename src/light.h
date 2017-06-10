#ifndef LIGHT_H
#define LIGHT_H

#include <QVector3D>



class Light
{
public:
    Light(QVector3D position, float intensity);

    QVector3D getPosition() const { return _position; }
    float getIntensity() const { return _intensity; }

private:
    QVector3D _position;
    float _intensity;
};

#endif // LIGHT_H
