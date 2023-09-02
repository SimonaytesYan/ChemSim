#include <cmath>

struct Vector
{
    double x, y;
    Vector(double x, double y);
    ~Vector();
};

Vector SumVector(Vector a, Vector b);
