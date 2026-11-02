#include <chrono>
#include <cstdio>

double maintenant()
{
    auto t = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration<double>(t).count();
}

class Chrono
{
public:
    Chrono() : debut(maintenant()) {}

    double ecoule() const
    {
        return maintenant() - debut;
    }

    void redemarrer()
    {
        debut = maintenant();
    }

private:
    double debut;
};

int main()
{
    long long total = 0;
    Chrono c;
    for (long long i = 0; i < 100000000; i++) total += i;
    std::printf("boucle : %.9f s\n", c.ecoule());
    std::printf("total = %lld\n", total);

    double durees[5];
    for (int k = 0; k < 5; k++)
    {
        c.redemarrer();
        durees[k] = c.ecoule();
    }
    for (int k = 0; k < 5; k++)
    {
        std::printf("court %d : %.9f s\n", k + 1, durees[k]);
    }

    const Chrono k;
    std::printf("k.ecoule() : %.9f s\n", k.ecoule());
    // k.redemarrer();
    return 0;
}
