#ifndef SCENE_H
#define SCENE_H

#include "light.h"
#include "object.h"

#include <QColor>
#include <QList>


class Scene
{
public:
    Scene(QColor ambient = QColor(0, 0, 0), float gamma = 0.1f);
    ~Scene();

    void addObject(Object* obj) { _objects.append(obj); }
    void addLight(Light* light) { _lights.append(light); }

    const QList<Object*>& getObjects() const { return _objects; }
    const QList<Light*>& getLights() const { return _lights; }

    QColor getAmbient() const { return _ambient; }
    float getGamma() const { return _gamma; }

private:
    QList<Object*> _objects;
    QList<Light*> _lights;

    QColor _ambient;
    float _gamma;
};

#endif // SCENE_H
