#include <cmath>
#include <cstdio>

struct Vec2
{
    double x;
    double y;
};

const double pi = 3.14159265358979323846;

Vec2 add(Vec2 a, Vec2 b)
{
    return {a.x + b.x, a.y + b.y};
}

Vec2 sub(Vec2 a, Vec2 b)
{
    return {a.x - b.x, a.y - b.y};
}

Vec2 scale(Vec2 a, double k)
{
    return {a.x * k, a.y * k};
}

double dot(Vec2 a, Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

double length(Vec2 a)
{
    return std::sqrt(dot(a, a));
}

Vec2 normalize(Vec2 a)
{
    double l = length(a);
    if (l == 0.0)
    {
        return {0.0, 0.0};
    }
    return {a.x / l, a.y / l};
}

Vec2 lerp(Vec2 a, Vec2 b, double t)
{
    return add(a, scale(sub(b, a), t));
}

Vec2 perp(Vec2 a)
{
    return {-a.y, a.x};
}

Vec2 rotate(Vec2 a, double angle)
{
    return {a.x * std::cos(angle) - a.y * std::sin(angle),
            a.x * std::sin(angle) + a.y * std::cos(angle)};
}

Vec2 reflect(Vec2 v, Vec2 n)
{
    return sub(v, scale(n, 2.0 * dot(v, n)));
}

double radians(double degres)
{
    return degres * pi / 180.0;
}

void afficher(const char* appel, Vec2 v)
{
    std::printf("%s = {%g, %g}\n", appel, v.x, v.y);
}

int main()
{
    const double epsilon = 1e-9;

    std::printf("length({3, 4}) = %g\n", length({3, 4}));
    std::printf("dot({1, 0}, {0, 1}) = %g\n", dot({1, 0}, {0, 1}));

    Vec2 r = rotate({1, 0}, radians(90));
    std::printf("rotate({1, 0}, radians(90)) = {%.17g, %.17g}\n", r.x, r.y);
    bool proche = std::fabs(r.x - 0.0) < epsilon && std::fabs(r.y - 1.0) < epsilon;
    std::printf("proche de {0, 1} a epsilon pres : %s\n", proche ? "oui" : "non");

    afficher("reflect({1, -1}, {0, 1})", reflect({1, -1}, {0, 1}));

    afficher("add({1, 2}, {3, 4})", add({1, 2}, {3, 4}));
    afficher("sub({5, 7}, {2, 3})", sub({5, 7}, {2, 3}));
    afficher("scale({1.5, -2}, 2)", scale({1.5, -2}, 2));
    afficher("normalize({3, 4})", normalize({3, 4}));
    afficher("normalize({0, 0})", normalize({0, 0}));
    afficher("lerp({0, 0}, {10, 20}, 0.25)", lerp({0, 0}, {10, 20}, 0.25));
    afficher("perp({2, 5})", perp({2, 5}));

    return 0;
}
