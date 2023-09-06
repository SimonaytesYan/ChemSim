#ifndef SYM_COORD_SYSTEM
#define SYM_COORD_SYSTEM

#include <SFML/Graphics.hpp>

class CoordSystem
{
    double x0;
    double y0;
    double unit_x;
    double unit_y;

    public : 
    CoordSystem(double X0 = 0, double Y0 = 0, 
                double unit_X = 1, double unit_Y = 1);
    ~CoordSystem();

    double GetX0() {return x0;};
    double GetY0() {return y0;};
    double GetUnitX() {return unit_x;};
    double GetUnitY() {return unit_y;};

    double СoordRecalcX(double x) {return x * unit_x + x0;};
    double СoordRecalcY(double y) {return -y * unit_y + y0;};

    void CoordSystemDraw(sf::RenderWindow* window);
};

#endif  //SYM_COORD_SYSTEM
