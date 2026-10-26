#include <chrono>
#include <cstdio>

double maintenant()
{
    auto t = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration<double>(t).count();
}

int main()
{
    long long total = 0;
    double debut = maintenant();
    for (int i = 1; i <= 1000000; i++)
    {
        total += i;
    }
    double fin = maintenant();
    std::printf("total = %lld\n", total);
    std::printf("boucle : %.9f s\n", fin - debut);

    double durees[5];
    for (int k = 0; k < 5; k++)
    {
        double avant = maintenant();
        std::printf("ligne courte\n");
        durees[k] = maintenant() - avant;
    }
    for (int k = 0; k < 5; k++)
    {
        std::printf("printf %d : %.9f s\n", k + 1, durees[k]);
    }
    return 0;
}
