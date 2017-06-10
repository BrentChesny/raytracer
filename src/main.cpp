#include "camera.h"
#include "mainwindow.h"
#include "raytracer.h"
#include "scene.h"
#include "sphere.h"
#include "light.h"
#include "plane.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Scene scene;
    Camera camera(QVector3D(0.0f, 0.0f, 1.0f), QVector3D(1.0f, 0.0f, 1.0f), 1.0f, 9.5f, 2.0f);
    RayTracer raytracer;

    //scene.addObject(new Plane(QColor(255, 255, 255), 0.3f, 0.0f, 1.0f, QVector3D(20.0f, 0.0f, 0.0f), QVector3D(-1.0f, 0.0f, 0.0f)));
    scene.addObject(new Plane(QColor(255, 255, 255), 0.3f, 0.0f, 1.0f, QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f)));

    scene.addObject(new Sphere(Qt::white, 0.5f, 2.0f, 500.0f, QVector3D(10.0f, -0.5f, 1.5f), 1.5f));
    scene.addObject(new Sphere(Qt::red, 0.5f, 2.0f, 500.0f, QVector3D(12, -4.8, 2.15), 2.15f));
    scene.addObject(new Sphere(Qt::red, 0.5f, 2.0f, 500.0f, QVector3D(5.5, -2.6, 0.83), 0.83f));
    scene.addObject(new Sphere(Qt::green, 0.5f, 2.0f, 500.0f, QVector3D(6.6, 1, 0.5), 0.5f));
    scene.addObject(new Sphere(Qt::red, 0.5f, 2.0f, 500.0f, QVector3D(8.5, 2.2, 0.5), 0.5f));
    scene.addObject(new Sphere(Qt::red, 0.5f, 2.0f, 500.0f, QVector3D(4.6, 2.15, 0.9), 0.9f));

    scene.addLight(new Light(QVector3D(1.0f, -8.0f, 10.0f), 2.0f));
    //scene.addLight(new Light(QVector3D(6.5f, -10.0f, 5.0f), 1.6f));

    QImage result = raytracer.render(scene, camera, 1024, 768);


    QLabel myLabel;
    myLabel.setPixmap(QPixmap::fromImage(result));
    myLabel.show();

    //return 0;

//    MainWindow w;
//    w.show();

    return a.exec();
}
