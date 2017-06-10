#include "scene.h"

Scene::Scene(QColor ambient, float gamma) :
    _ambient(ambient), _gamma(gamma)
{

}

Scene::~Scene()
{
    qDeleteAll(_objects);
    qDeleteAll(_lights);
}
