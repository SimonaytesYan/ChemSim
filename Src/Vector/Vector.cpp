#include "Vector.h"

Vector::Vector(double x, double y) :
x (x),
y (y)
{}

Vector::~Vector()
{
    this->x = NAN;
    this->y = NAN;
}

Vector SumVector(Vector a, Vector b)
{
    //Vector res = a + b
    //return res 
}
