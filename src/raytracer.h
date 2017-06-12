#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "camera.h"
#include "scene.h"
#include "intersection.h"

#include <QImage>


class RayTracer
{
public:
    RayTracer();

    QImage render(const Scene &scene, const Camera &camera, int width = 640, int height = 480, int maxDepth = 3);

private:
    Color trace(const Scene &scene, const Ray &ray, int maxDepth, int depth);
    Intersection* findClosestIntersection(const Scene &scene, const Ray &ray);

    static const float EPSILON;
};

#endif // RAYTRACER_H
