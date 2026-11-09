#include <cstdio>

class Base
{
public:
    Base() : publique(1), protegee(2), privee(3) {}
    int publique;

protected:
    int protegee;

private:
    int privee;
};

class Derivee : public Base
{
public:
    void afficher() const
    {
        std::printf("derivee : publique = %d\n", publique);
        std::printf("derivee : protegee = %d\n", protegee);
        //std::printf("derivee : privee = %d\n", privee);
    }
};

// void soigner(Base& b)
// {
//    b.protegee = 1;
//}

int main()
{
    Derivee d;
    d.afficher();
    std::printf("main : publique = %d\n", d.publique);
    // std::printf("main : protegee = %d\n", d.protegee);
    // std::printf("main : privee = %d\n", d.privee);
    return 0;
}
