#include <chrono>
#include <cstdio>
#include <cstdlib>

long appels = 0;

double maintenant()
{
    auto t = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration<double>(t).count();
}

void mettreAJour(double dt)
{
    (void)dt;
    appels++;
}

double dureeAuHasard(double maxAttente)
{
    double fraction = std::rand() / static_cast<double>(RAND_MAX);
    return maxAttente / 2.0 + fraction * maxAttente / 2.0;
}

void attendre(double duree)
{
    double fin = maintenant() + duree;
    while (maintenant() < fin)
    {
    }
}

int main(int argc, char** argv)
{
    double maxAttente = 0.001;
    if (argc > 1)
    {
        maxAttente = std::atof(argv[1]) / 1000.0;
    }

    const double PAS = 1.0 / 120.0;
    double accumulateur = 0.0;
    double debut = maintenant();
    double precedent = debut;
    long tours = 0;
    bool enCours = true;

    while (enCours)
    {
        double actuel = maintenant();
        accumulateur += actuel - precedent;
        precedent = actuel;
        while (accumulateur >= PAS)
        {
            mettreAJour(PAS);
            accumulateur -= PAS;
        }
        attendre(dureeAuHasard(maxAttente));
        tours++;
        enCours = maintenant() - debut < 10.0;
    }

    std::printf("attente max : %g ms\n", maxAttente * 1000.0);
    std::printf("tours : %ld\n", tours);
    std::printf("appels : %ld\n", appels);
    std::printf("duree : %.3f s\n", maintenant() - debut);

    return 0;
}
