#include <cstdio>

struct Vec2
{
    double x;
    double y;
};

struct Particule
{
    Vec2   position;
    Vec2   vitesse;
    double vie;
};

struct A { char c; int n; };
struct B { char c; double d; char e; };
struct C { double d; char c; char e; };

struct ParticuleEtat
{
    double vie;
    char   etat;
    Vec2   position;
    Vec2   vitesse;
};

struct Ordre1
{
    Vec2   position;
    Vec2   vitesse;
    double vie;
    char   etat;
};

struct Ordre2
{
    char   etat;
    double vie;
    Vec2   position;
    Vec2   vitesse;
};

struct Ordre3
{
    Vec2   position;
    char   etat;
    Vec2   vitesse;
    double vie;
};

int main()
{
    std::printf("Vec2 16 %zu\n", sizeof(Vec2));
    std::printf("Particule 40 %zu\n", sizeof(Particule));
    std::printf("A 5 %zu\n", sizeof(A));
    std::printf("B 10 %zu\n", sizeof(B));
    std::printf("C 10 %zu\n", sizeof(C));
    std::printf("ParticuleEtat 41 %zu\n", sizeof(ParticuleEtat));

    std::printf("position, vitesse, vie, etat %zu\n", sizeof(Ordre1));
    std::printf("etat, vie, position, vitesse %zu\n", sizeof(Ordre2));
    std::printf("position, etat, vitesse, vie %zu\n", sizeof(Ordre3));

    return 0;
}
