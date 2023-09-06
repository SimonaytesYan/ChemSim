#include <cmath>

#include "CoordSystem.h"

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

void CoordSystem::CoordSystemDraw(sf::RenderWindow* window)
{
    sf::Vertex OX[] =
    {
        sf::Vertex(sf::Vector2f(0, y0)),
        sf::Vertex(sf::Vector2f(window->getSize().x, y0))
    };

    sf::Vertex OY[] =
    {
        sf::Vertex(sf::Vector2f(x0, 0)),
        sf::Vertex(sf::Vector2f(x0, window->getSize().y))
    };

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

    window->draw(OX, 2, sf::Lines);
    window->draw(OY, 2, sf::Lines);
}
