#include <cmath>
#include <cstdio>

struct Vec2
{
    double x, y;
    Vec2() : x(0.0), y(0.0) {}
    Vec2(double x_, double y_) : x(x_), y(y_) {}
};

Vec2 operator+(const Vec2& a, const Vec2& b)
{
    return Vec2(a.x + b.x, a.y + b.y);
}

Vec2 operator*(const Vec2& a, double k)
{
    return Vec2(a.x * k, a.y * k);
}

int main()
{
    Vec2 a(1.0, 2.0), b(3.0, 4.0);
    a += b;
    Vec2 c = 2.0 * a;
    return 0;
}