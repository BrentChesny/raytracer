#ifndef COLOR_H
#define COLOR_H

#include <QColor>

class Color : public QColor
{
public:
    static const Color WHITE;
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;

    Color(int r, int g, int b);

    Color operator*(float scalar);
    Color operator*(const Color &color);
    Color operator+(const Color &color);

    Color& operator += (const Color& color);
};

//Color operator*(float scalar, Color color)
//{
//    return color * scalar;
//}

#endif // COLOR_H
