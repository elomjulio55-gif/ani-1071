#include <cstdio>

class Trace
{
public:
    Trace(const char* n) : nom(n)
    {
        std::printf("%s nait\n", nom);
    }

    ~Trace()
    {
        std::printf("%s meurt\n", nom);
    }

private:
    const char* nom;
};

void f()
{
    Trace t("fonction");
    std::printf("fin de la fonction\n");
}

int main()
{
    Trace m("m");
    f();
    {
        Trace b("bloc");
        std::printf("fin du bloc\n");
    }
    new Trace("new_sans_delete");
    Trace* q = new Trace("new_avec_delete");
    delete q;
    {
        Trace d1("double_1");
        Trace d2("double_2");
        std::printf("fin du bloc double\n");
    }
    std::printf("fin de main\n");
    m.~Trace();
    return 0;
}
