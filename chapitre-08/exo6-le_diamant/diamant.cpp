#include <cstdio>

struct Vec2
{
    double x, y;
};

namespace simple
{
struct Entite
{
    Vec2 position = Vec2{0.0, 0.0};
};

struct Mobile : public Entite
{
    Vec2 vitesse = Vec2{0.0, 0.0};
};

struct Visible : public Entite
{
    char glyphe = 'E';
};

struct Ennemi : public Mobile, public Visible
{
};
}

namespace virtuel
{
struct Entite
{
    Vec2 position = Vec2{0.0, 0.0};
};

struct Mobile : virtual public Entite
{
    Vec2 vitesse = Vec2{0.0, 0.0};
};

struct Visible : virtual public Entite
{
    char glyphe = 'E';
};

struct Ennemi : public Mobile, public Visible
{
};
}

int main()
{
    std::printf("sans virtual :\n");
    std::printf("sizeof(Entite) = %d\n", (int)sizeof(simple::Entite));
    std::printf("sizeof(Mobile) = %d\n", (int)sizeof(simple::Mobile));
    std::printf("sizeof(Visible) = %d\n", (int)sizeof(simple::Visible));
    std::printf("sizeof(Ennemi) = %d\n", (int)sizeof(simple::Ennemi));
    simple::Ennemi a;
    // a.position.x = 3.0;
    a.Mobile::position.x = 3.0;
    simple::Mobile& ma = a;
    simple::Visible& va = a;
    std::printf("Mobile& : position.x = %.1f\n", ma.position.x);
    std::printf("Visible& : position.x = %.1f\n", va.position.x);

    std::printf("\navec virtual :\n");
    std::printf("sizeof(Entite) = %d\n", (int)sizeof(virtuel::Entite));
    std::printf("sizeof(Mobile) = %d\n", (int)sizeof(virtuel::Mobile));
    std::printf("sizeof(Visible) = %d\n", (int)sizeof(virtuel::Visible));
    std::printf("sizeof(Ennemi) = %d\n", (int)sizeof(virtuel::Ennemi));
    virtuel::Ennemi b;
    b.position.x = 3.0;
    virtuel::Mobile& mb = b;
    virtuel::Visible& vb = b;
    std::printf("Mobile& : position.x = %.1f\n", mb.position.x);
    std::printf("Visible& : position.x = %.1f\n", vb.position.x);
    return 0;
}
