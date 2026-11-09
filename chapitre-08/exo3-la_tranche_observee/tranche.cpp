#include <cstdio>

class Entite
{
public:
    virtual const char* nom() const
    {
        return "entite";
    }

    virtual ~Entite() {}
};

class Ennemi : public Entite
{
public:
    const char* nom() const override
    {
        return "ennemi";
    }

private:
    int degats = 5;
};

void f(Entite e)
{
    std::printf("f (valeur) : %s\n", e.nom());
}

void g(Entite& e)
{
    std::printf("g (reference) : %s\n", e.nom());
}

void h(Entite* e)
{
    std::printf("h (pointeur) : %s\n", e->nom());
}

int main()
{
    Ennemi e;
    f(e);
    g(e);
    h(&e);
    std::printf("sizeof(Entite) = %d\n", (int)sizeof(Entite));
    std::printf("sizeof(Ennemi) = %d\n", (int)sizeof(Ennemi));
    return 0;
}
