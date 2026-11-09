#include <cmath>
#include <cstdio>

const double pi = 3.14159265358979323846;

double lerp(double a, double b, double t)
{
    return a + (b - a) * t;
}

double lerpAngle(double a, double b, double t)
{
    double d = b - a;
    while (d > pi)
    {
        d -= 2.0 * pi;
    }
    while (d < -pi)
    {
        d += 2.0 * pi;
    }
    return a + d * t;
}

double ramener360(double deg)
{
    deg = std::fmod(deg, 360.0);
    if (deg < 0.0)
    {
        deg += 360.0;
    }
    if (deg >= 360.0)
    {
        deg -= 360.0;
    }
    return deg + 0.0;
}

double lerpAngleDeg(double a, double b, double t)
{
    double rad = lerpAngle(a * pi / 180.0, b * pi / 180.0, t);
    return ramener360(rad * 180.0 / pi);
}

int main()
{
    double departs[3] = {350.0, 10.0, 0.0};
    double arrivees[3] = {10.0, 350.0, 180.0};
    for (int k = 0; k < 3; k++)
    {
        std::printf("de %.0f vers %.0f :\n", departs[k], arrivees[k]);
        for (int i = 0; i <= 10; i++)
        {
            double t = i / 10.0;
            std::printf("t = %.1f : lerp = %.1f  lerpAngle = %.1f\n", t,
                        ramener360(lerp(departs[k], arrivees[k], t)),
                        lerpAngleDeg(departs[k], arrivees[k], t));
        }
        std::printf("\n");
    }

    double cap = 340.0;
    double cameraSimple = 340.0;
    double cameraAngle = 340.0;
    std::printf("camera :\n");
    for (int pas = 1; pas <= 12; pas++)
    {
        cap = ramener360(cap + 4.0);
        cameraSimple = lerp(cameraSimple, cap, 0.3);
        cameraAngle = lerpAngleDeg(cameraAngle, cap, 0.3);
        std::printf("pas %d : cap = %.1f  lerp = %.1f  lerpAngle = %.1f\n", pas, cap, cameraSimple, cameraAngle);
    }
    return 0;
}
