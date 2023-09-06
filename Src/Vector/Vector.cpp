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
    double r = sqrt(coord_sys->GetUnitX() * coord_sys->GetUnitY())/25;
    sf::CircleShape circle(r);
    
    circle.setPosition(x1 - r, y1 - r);
    circle.setFillColor(color);

    window->draw(circle);

}

/*static void DrawTriangleTip(sf::RenderWindow* window, CoordSystem* coord_sys, 
                            Vector* vec, sf::Color color)
{
    double length_tr_side = sqrt(coord_sys->GetUnitX() * coord_sys->GetUnitY())/10;

    double length_x1_y1 = sqrt(vec.GetX() * vec.GetX() + vec.GetY() * vec.GetY());
    double new_x1       = -vec.GetX() / length_x1_y1 * length_tr_side;
    double new_y1       = -vec.GetY() / length_x1_y1 * length_tr_side;

    Vector left_side(new_x1, new_y1, sf::Color(0, 255, 255));
    Vector right_side(new_x1, new_y1, sf::Color(0, 255, 255));
    
    left_side.RotateVector(30);
    right_side.RotateVector(330);

    //printf("left.x = %lg left.y = %lg\n", left_side.GetX(), left_side.GetY());
    //printf("right.x = %lg right.y = %lg\n", right_side.GetX(), right_side.GetY());

    sf::Vertex tip[] = 
    {
        sf::Vertex(sf::Vector2f(x1, y1), color),
        sf::Vertex(sf::Vector2f(x1 + left_side.GetX(), y1 + left_side.GetY()), color),
        sf::Vertex(sf::Vector2f(x1 + right_side.GetX(), y1 + right_side.GetY()), color)
    };

    window->draw(tip, 3, sf::Lines);
}*/

void Vector::DrawVector(sf::RenderWindow* window, CoordSystem* coord_sys,  
                        double x0, double y0)
{
    double x1 = coord_sys->СoordRecalcX(x + x0);
    double y1 = coord_sys->СoordRecalcY(y + y0);
    x0 = coord_sys->СoordRecalcX(x0);
    y0 = coord_sys->СoordRecalcY(y0);

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(x0, y0), color),
        sf::Vertex(sf::Vector2f(x1, y1), color)
    };

    DrawCircleTip(window, coord_sys, x1, y1, color);

    //DrawTriangleTip(window, coord_sys, x1, y1, color);

    window->draw(line, 2, sf::Lines);
}

double Vector::VecLength()
{
    return sqrt(x*x + y*y);
}

void Vector::RotateVector(double deg)
{
    double rot_x = cos(deg);
    double rot_y = sin(deg);

    double old_x = x;
    double old_y = y;
    x = old_x * rot_x - old_y * rot_y;
    y = old_y * rot_x + old_x * rot_y;
}
