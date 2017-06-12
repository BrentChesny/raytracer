#include "scene.h"

Scene::Scene(Color ambient, float gamma) :
    _ambient(ambient), _gamma(gamma)
{

}

Scene::~Scene()
{
    qDeleteAll(_objects);
    qDeleteAll(_lights);
}
