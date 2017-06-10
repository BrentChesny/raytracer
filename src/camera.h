#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>


class Camera
{
public:
    Camera(QVector3D position, QVector3D lookAt, float fov = 10.0f, float focus = 3.8f, float focal = 7.5f);

    float getFov() const { return _fov; }
    QVector3D getPosition() const { return _position; }
    QVector3D getLookAt() const { return _lookAt; }
    QVector3D getUp() const { return _up; }
    QVector3D getRight() const { return _right; }

private:
    QVector3D _position;
    QVector3D _lookAt;
    QVector3D _direction;
    QVector3D _up;
    QVector3D _right;

    float _fov;
    float _focus;
    float _focal;
};

#endif // CAMERA_H
