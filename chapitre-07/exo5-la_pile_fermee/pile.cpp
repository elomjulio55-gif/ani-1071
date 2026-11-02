#include <iostream>

class Pile
{
private:
    static const int CAPACITE = 100;
    int elements[CAPACITE];
    int nombre;

public:
    Pile() : nombre(0) {}

    void empiler(int v)
    {
        if (!pleine())
            elements[nombre++] = v;
    }

    int depiler()
    {
        if (vide())
            return -1;

        return elements[--nombre];
    }

    int sommet() const
    {
        if (vide())
            return -1;

        return elements[nombre - 1];
    }

    bool vide() const
    {
        return nombre == 0;
    }

    int taille() const
    {
        return nombre;
    }

    bool pleine() const
    {
        return nombre == CAPACITE;
    }
};

class File
{
private:
    static const int CAPACITE = 100;
    int elements[CAPACITE];
    int tete;
    int queue;
    int nombre;

public:
    File() : tete(0), queue(0), nombre(0) {}

    void enfiler(int v)
    {
        if (pleine())
            return;

        elements[queue] = v;
        queue = (queue + 1) % CAPACITE;
        nombre++;
    }

    int defiler()
    {
        if (nombre == 0)
            return -1;

        int v = elements[tete];
        tete = (tete + 1) % CAPACITE;
        nombre--;

        return v;
    }

    int taille() const
    {
        return nombre;
    }

    bool pleine() const
    {
        return nombre == CAPACITE;
    }
};

int main()
{
    Pile p;
    File f;

    // p.nombre = -5;
    // f.tete = 7;

    for (int i = 0; i < 150; i++)
        p.empiler(i);

    std::cout << "Taille de la pile apres 150 empilements : " << p.taille() << std::endl;

    for (int i = 0; i < 200; i++)
        p.depiler();

    std::cout << "Taille de la pile apres 200 depilements : " << p.taille() << std::endl;

    for (int i = 0; i < 150; i++)
        f.enfiler(i);

    std::cout << "Taille de la file apres 150 enfilements : " << f.taille() << std::endl;

    for (int i = 0; i < 200; i++)
        f.defiler();

    std::cout << "Taille de la file apres 200 defilements : " << f.taille() << std::endl;

    for (int i = 0; i < 150; i++)
        f.enfiler(i);

    std::cout << "Taille de la file apres 150 nouveaux enfilements : " << f.taille() << std::endl;

    return 0;
}
