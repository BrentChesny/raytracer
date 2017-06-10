#include "camera.h"

Camera::Camera(QVector3D position, QVector3D lookAt, float fov, float focus, float focal) :
    _position(position), _lookAt(lookAt), _fov(fov), _focus(focus), _focal(focal)
{
    _direction = (_lookAt - _position).normalized();
    _up = QVector3D::crossProduct(_direction, QVector3D::crossProduct(QVector3D(0.0f, 0.0f, 1.0f), _direction)).normalized();
    _right = QVector3D::crossProduct(_up, _direction);
}
