#include <cmath>
#include <cstdio>

struct Vec2
{
    double x;
    double y;
};

void bougerCopie(Vec2 p)
{
    p.x += 1;
}

void bougerRef(Vec2& p)
{
    p.x += 1;
}

double longueurRef(const Vec2& p)
{
    p.x = 0;
    return std::sqrt(p.x * p.x + p.y * p.y);
}

void afficher(const char* etape, const Vec2& p)
{
    std::printf("%s : x = %g, y = %g\n", etape, p.x, p.y);
}

int main()
{
    Vec2 p = {2, 4};
    afficher("depart", p);

    bougerCopie(p);
    afficher("apres bougerCopie", p);

    bougerRef(p);
    afficher("apres bougerRef", p);

    double l = longueurRef(p);
    afficher("apres longueurRef", p);
    std::printf("longueurRef rend %g\n", l);

    return 0;
}
