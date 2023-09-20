#include <cmath>

#include "CoordSystem.h"
#include "../Vector/Vector.h"
#include "../SubWindow/SubWindow.h"

CoordSystem::CoordSystem(double X0, double Y0, double unit_X, double unit_Y) :
x0 (X0),
y0 (Y0),
unit_x (unit_X),
unit_y (unit_Y)
{}

CoordSystem::~CoordSystem()
{
    x0     = NAN;
    y0     = NAN;
    unit_x = NAN;
    unit_y = NAN;
}

void CoordSystem::CoordSystemDraw(SubWindow* window)
{
    Vector OX((window->getSize().x - kThicknessWeight) / this->unit_x, 0);
    Vector OY(0, (window->getSize().y - kThicknessWeight) / this->unit_y);

    OX.Draw(window, this, -(window->getSize().x / this->unit_x) / 2, 0);
    OY.Draw(window, this, 0, -(window->getSize().y / this->unit_y) / 2);

    double r_x = unit_x / 30;
    double r_y = unit_y / 30;

    for (double x = x0; x < window->getSize().x; x += unit_x)
    {
        sf::CircleShape circle(r_x);
        circle.setPosition(x - r_x, y0 - r_x);

        window->draw(circle);
    }

    for (double y = y0; y < window->getSize().x; y += unit_y)
    {
        sf::CircleShape circle(r_y);
        circle.setPosition(x0 - r_y, y - r_y);

        window->draw(circle);
    }

    for (double x = x0; x > 0; x -= unit_x)
    {
        sf::CircleShape circle(r_x);
        circle.setPosition(x - r_x, y0 - r_x);

        window->draw(circle);
    }

    for (double y = y0; y > 0; y -= unit_y)
    {
        sf::CircleShape circle(r_y);
        circle.setPosition(x0 - r_y, y - r_y);

        window->draw(circle);
    }
}
