#include <cmath>
#include <cstdio>

struct Vec2
{
    double x, y;

    Vec2() : x(0.0), y(0.0) {}
    Vec2(double x_, double y_) : x(x_), y(y_) {}

    double length() const
    {
        return std::sqrt(x * x + y * y);
    }

    double dot(Vec2 b) const
    {
        return x * b.x + y * b.y;
    }

    Vec2 normalized() const
    {
        double l = length();
        if (l == 0.0)
        {
            return Vec2();
        }
        return Vec2(x / l, y / l);
    }

    void normalize()
    {
        *this = normalized();
    }

    Vec2& operator+=(const Vec2& b)
    {
        x += b.x;
        y += b.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& b)
    {
        x -= b.x;
        y -= b.y;
        return *this;
    }

    Vec2& operator*=(double k)
    {
        x *= k;
        y *= k;
        return *this;
    }

    double& operator[](int i)
    {
        return i == 0 ? x : y;
    }

    double operator[](int i) const
    {
        return i == 0 ? x : y;
    }
};

Vec2 operator+(const Vec2& a, const Vec2& b)
{
    return Vec2(a.x + b.x, a.y + b.y);
}

Vec2 operator-(const Vec2& a, const Vec2& b)
{
    return Vec2(a.x - b.x, a.y - b.y);
}

Vec2 operator-(const Vec2& a)
{
    return Vec2(-a.x, -a.y);
}

Vec2 operator*(const Vec2& a, double k)
{
    return Vec2(a.x * k, a.y * k);
}

Vec2 operator*(double k, const Vec2& a)
{
    return a * k;
}

Vec2 operator/(const Vec2& a, double k)
{
    return Vec2(a.x / k, a.y / k);
}

bool operator==(const Vec2& a, const Vec2& b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vec2& a, const Vec2& b)
{
    return !(a == b);
}

void afficher(const char* nom, const Vec2& v)
{
    std::printf("%s = (%g, %g)\n", nom, v.x, v.y);
}

void afficherOuiNon(const char* nom, bool b)
{
    std::printf("%s : %s\n", nom, b ? "oui" : "non");
}

double instantSol(double y0, double vy, double gy)
{
    double a = gy / 2.0;
    return (-vy - std::sqrt(vy * vy - 4.0 * a * y0)) / (2.0 * a);
}

int main()
{
    Vec2 o;
    Vec2 a(3.0, 4.0);
    Vec2 b(1.0, 2.0);
    afficher("Vec2()", o);
    afficher("Vec2(3, 4) = a", a);
    afficher("Vec2(1, 2) = b", b);
    std::printf("a.length() = %g\n", a.length());
    std::printf("a.dot(b) = %g\n", a.dot(b));
    afficher("a.normalized()", a.normalized());
    Vec2 n = a;
    n.normalize();
    afficher("n = a; n.normalize(); n", n);
    afficher("a (inchangé)", a);
    Vec2 z;
    z.normalize();
    afficher("Vec2().normalize()", z);
    afficher("a + b", a + b);
    afficher("a - b", a - b);
    afficher("-a", -a);
    afficher("a / 2.0", a / 2.0);
    afficher("a * 2.0", a * 2.0);
    afficher("2.0 * a", 2.0 * a);
    afficherOuiNon("a == b", a == b);
    afficherOuiNon("a == Vec2(3, 4)", a == Vec2(3.0, 4.0));
    afficherOuiNon("a != b", a != b);
    Vec2 c = a;
    c += b;
    afficher("c = a; c += b; c", c);
    c -= b;
    afficher("c -= b; c", c);
    c *= 2.0;
    afficher("c *= 2.0; c", c);
    Vec2 d = a;
    (d += b) += b;
    afficher("d = a; (d += b) += b; d", d);
    std::printf("a[0] = %g, a[1] = %g\n", a[0], a[1]);
    c[1] = 5.0;
    afficher("c[1] = 5.0; c", c);

    std::printf("\n");

    Vec2 p0(0.0, 10.0);
    Vec2 v0(3.0, 0.0);
    Vec2 g(0.0, -9.81);
    double dt = 0.1;
    Vec2 p = p0;
    Vec2 v = v0;
    int pas = 0;
    while (p.y >= 0.0)
    {
        v += g * dt;
        p += v * dt;
        pas++;
        std::printf("pas %d : t = %.1f  p = (%.4f, %.4f)  v = (%.4f, %.4f)\n",
                    pas, pas * dt, p.x, p.y, v.x, v.y);
    }

    std::printf("\n");

    std::printf("instant de la formule : %.4f s\n", instantSol(p0.y, v0.y, g.y));
    std::printf("premier pas avec p.y < 0 : %d (t = %.1f s)\n", pas, pas * dt);
    return 0;
}
