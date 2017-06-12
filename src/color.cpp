#include "color.h"

#include <QtGlobal>


const Color Color::WHITE = Color(255, 255, 255);
const Color Color::RED = Color(255, 0, 0);
const Color Color::GREEN = Color(0, 255, 0);
const Color Color::BLUE = Color(0, 0, 255);


Color::Color(int r, int g, int b) :
    QColor(r, g, b)
{

}

Color Color::operator*(float scalar)
{
    int r = qBound(0, (int) (scalar * this->red()), 255);
    int g = qBound(0, (int) (scalar * this->green()), 255);
    int b = qBound(0, (int) (scalar * this->blue()), 255);

    return Color(r, g, b);
}

Color Color::operator*(const Color &color)
{
    int r = qBound(0, (this->red() * color.red()) / 255, 255);
    int g = qBound(0, (this->green() * color.green()) / 255, 255);
    int b = qBound(0, (this->blue() * color.blue()) / 255, 255);

    return Color(r, g, b);
}

Color Color::operator+(const Color &color)
{
    int r = qBound(0, this->red() + color.red(), 255);
    int g = qBound(0, this->green() + color.green(), 255);
    int b = qBound(0, this->blue() + color.blue(), 255);

    return Color(r, g, b);
}

Color &Color::operator +=(const Color &color)
{
    int r = qBound(0, this->red() + color.red(), 255);
    int g = qBound(0, this->green() + color.green(), 255);
    int b = qBound(0, this->blue() + color.blue(), 255);

    this->setRgb(r, g, b);
}
