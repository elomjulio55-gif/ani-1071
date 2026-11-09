#include <cstdio>

struct Vec2
{
    double x, y;
};

class Entite
{
public:
    Entite(Vec2 p, const char* n) : position(p), nom(n) {}

protected:
    Vec2 position;
    const char* nom;
};

class Ennemi : public Entite
{
public:
    Ennemi(Vec2 p, const char* n, int d) : Entite(p, n), degats(d) {}

    void deplacer(Vec2 nouvelle)
    {
        position = nouvelle;
    }

private:
    int degats;
};

class Joueur : public Entite
{
public:
    Joueur(Vec2 p, const char* n, double v) : Entite(p, n), vie(v) {}

private:
    double vie;
};

int main()
{
    Ennemi e(Vec2{0.0, 0.0}, "gobelin", 5);
    Joueur j(Vec2{1.0, 2.0}, "hero", 100.0);
    e.deplacer(Vec2{3.0, 4.0});
     //e.position = Vec2{3.0, 4.0};

    std::printf("sizeof(Vec2) = %d\n", (int)sizeof(Vec2));
    std::printf("sizeof(const char*) = %d\n", (int)sizeof(const char*));
    std::printf("sizeof(Entite) = %d\n", (int)sizeof(Entite));
    std::printf("sizeof(Ennemi) = %d\n", (int)sizeof(Ennemi));
    std::printf("sizeof(Joueur) = %d\n", (int)sizeof(Joueur));
    return 0;
}
