#ifndef SYM_GEOM_VECTOR
#define SYM_GEOM_VECTOR

#include <SFML/Graphics.hpp>

#include "../CoordSystem/CoordSystem.h"

class Vector
{
    double x;
    double y;

    sf::Color color;

    public : 
    Vector(double x, double y, sf::Color color);
    ~Vector();

    double GetX() {return x;};
    double GetY() {return y;};

    void DrawVector(sf::RenderWindow* window, CoordSystem* coord_sys,  
                    double x0, double y0);
    double VecLength();
    void RotateVector(double deg);

    friend Vector SumVector(Vector a, Vector b);
};

Vector SumVector(Vector a, Vector b);

#endif //SYM_GEOM_VECTOR
