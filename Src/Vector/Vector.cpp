#include <cmath>

#include "Vector.h"

Vector::Vector(double x, double y, sf::Color color) :
x (x),
y (y),
color (color)
{}

Vector::~Vector()
{
    this->x = NAN;
    this->y = NAN;
}

Vector SumVector(Vector a, Vector b)
{
    sf::Color new_color = sf::Color((a.color.r + b.color.r)/2, 
                                    (a.color.g + b.color.g)/2,
                                    (a.color.b + b.color.b)/2);

    Vector res = Vector(a.x + b.x, a.y + b.y, new_color);
    return res;
}

static void DrawCircleTip(sf::RenderWindow* window, CoordSystem* coord_sys, 
                          double x1, double y1, sf::Color color)
{
    double r = ((coord_sys->GetUnitX() + coord_sys->GetUnitY()) / 2) / 25;
    sf::CircleShape circle(r);
    
    circle.setPosition(x1 - r, y1 - r);
    circle.setFillColor(color);

    window->draw(circle);

}

static void DrawTriangleTip(sf::RenderWindow* window, CoordSystem* coord_sys, 
                            Vector* vec, double x0, double y0)
{
    double x1 = vec->GetX() + x0;
    double y1 = vec->GetY() + y0;
    
    double new_x = -vec->GetX() / vec->VecLength() / 10;
    double new_y = -vec->GetY() / vec->VecLength() / 10;

    Vector left_side(new_x, new_y);
    Vector right_side(new_x, new_y);

    left_side.RotateVector(45);
    right_side.RotateVector(315);

    double vertex_coords[] = {x1, y1,
                              left_side.GetX() + x1, left_side.GetY() + y1,
                              right_side.GetX() + x1,right_side.GetY() + y1};

    sf::VertexArray tip(sf::Triangles, 3);
    for (int i = 0; i < 3; i++)
    {
        vertex_coords[i*2]     = coord_sys->СoordRecalcX(vertex_coords[i*2]);
        vertex_coords[i*2 + 1] = coord_sys->СoordRecalcY(vertex_coords[i*2 + 1]);

        tip[i] = sf::Vertex(sf::Vector2f(vertex_coords[i*2], vertex_coords[i*2 + 1]), vec->GetColor());
    }

    window->draw(tip);
}

void Vector::DrawVector(sf::RenderWindow* window, CoordSystem* coord_sys,  
                        double x0, double y0)
{
    DrawTriangleTip(window, coord_sys, this, x0, y0);

    double x1 = coord_sys->СoordRecalcX(x + x0);
    double y1 = coord_sys->СoordRecalcY(y + y0);

    x0 = coord_sys->СoordRecalcX(x0);
    y0 = coord_sys->СoordRecalcY(y0);

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(x0, y0), color),
        sf::Vertex(sf::Vector2f(x1, y1), color)
    };

    window->draw(line, 2, sf::Lines);
}

double Vector::VecLength()
{
    return sqrt(x*x + y*y);
}

void Vector::RotateVector(double deg)
{
    double rad = M_PI / 180 * deg;

    double rot_x = cos(rad);
    double rot_y = sin(rad);

    double old_x = x;
    double old_y = y;
    x = old_x * rot_x - old_y * rot_y;
    y = old_y * rot_x + old_x * rot_y;
}
