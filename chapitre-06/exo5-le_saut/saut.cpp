#include <cmath>
#include <cstdio>

struct Vec2
{
    double x;
    double y;
};

const double g = 9.81;

void eulerSemiImplicite(Vec2& p, Vec2& v, Vec2 a, double dt)
{
    v.x += a.x * dt;
    v.y += a.y * dt;
    p.x += v.x * dt;
    p.y += v.y * dt;
}

double hauteurMax(double v0, double dt)
{
    Vec2 p = {0.0, 0.0};
    Vec2 v = {0.0, v0};
    Vec2 a = {0.0, -g};
    double maximum = 0.0;
    do
    {
        eulerSemiImplicite(p, v, a, dt);
        if (p.y > maximum)
        {
            maximum = p.y;
        }
    } while (p.y > 0.0);
    return maximum;
}

int main()
{
    const double h = 3.0;
    double v0 = std::sqrt(2.0 * g * h);

    std::printf("v0 : %.6f\n", v0);
    std::printf("formule v0 * v0 / (2 * g) : %.6f\n", v0 * v0 / (2.0 * g));
    std::printf("1/120 : %.6f\n", hauteurMax(v0, 1.0 / 120.0));
    std::printf("1/30 : %.6f\n", hauteurMax(v0, 1.0 / 30.0));
    std::printf("Mon pas : 1/1000 %.6f\n", hauteurMax(v0, 1.0 / 1000.0));

    return 0;
}
