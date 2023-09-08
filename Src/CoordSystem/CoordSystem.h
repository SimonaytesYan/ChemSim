#ifndef SYM_COORD_SYSTEM
#define SYM_COORD_SYSTEM

#include <SFML/Graphics.hpp>

#include "../SubWindow/SubWindow.h"

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

    double СoordRecalcX(double x)   //from x in coordination system makes x on the window
    {return x * unit_x + x0;};
    double СoordRecalcY(double y)   //from y in coordination system makes y on the window
    {return -y * unit_y + y0;};

    double CoordReverseRecalcX(double x)   //from x on the window makes x in coordination system
    {return (x - x0) / unit_x;};
    double CoordReverseRecalcY(double y)   //from y on the window makes y in coordination system
    {return -(y - y0) / unit_x;};

    void CoordSystemDraw(SubWindow* window);
};

#endif  //SYM_COORD_SYSTEM
