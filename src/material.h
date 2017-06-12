#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"


class Material
{
public:
    Material(const Color &color, float Ka = 0.2f, float Kd = 0.6f, float Ks = 0.6f, float reflectivity = 0.13f, float shininess = 100.0f);

    float Ka() const;
    void setKa(float Ka);

    float Kd() const;
    void setKd(float Kd);

    float Ks() const;
    void setKs(float Ks);

    float reflectivity() const;
    void setReflectivity(float reflectivity);

    float shininess() const;
    void setShininess(float shininess);

    Color color() const;
    void setColor(const Color &color);

private:
    Color _color;

    float _Ka;
    float _Kd;
    float _Ks;
    float _reflectivity;
    float _shininess;
};

#endif // MATERIAL_H
