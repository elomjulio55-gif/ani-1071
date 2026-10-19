#include <cstdio>
#include <cmath>

using Fonction = double (*)(double);

double integrale(Fonction f, double a, double b) {
    double pas = (b - a) / 1000;
    double somme = 0;
    for (int i = 0; i < 1000; i++) {
        somme += f(a + i * pas) * pas;   
    }
    return somme;
}

double derivee(Fonction f, double x) {
    double h = 1e-6;
    return (f(x + h) - f(x - h)) / (2 * h);
}

double zero(Fonction f, double a, double b) {
    double fa = f(a);
    for (int tour = 0; tour < 100; tour++) {   
        double m = (a + b) / 2;
        double fm = f(m);
        if (fa * fm <= 0) {
            b = m;            
        } else {
            a = m;            
            fa = fm;
        }
    }
    return (a + b) / 2;
}

double carre(double x) { return x * x; }
double carreMoinsDeux(double x) { return x * x - 2; }

int main() {
    double i1 = integrale(std::sin, 0, 3.14159);
    double i2 = integrale(carre, 0, 1);
    double d = derivee(std::sin, 0);
    double z = zero(carreMoinsDeux, 1, 2);
    double ecart = std::fabs(z - std::sqrt(2.0));

    printf("Integrale : sin entre 0 et 3.14159 = %.6f ; carre entre 0 et 1 = %.6f\n", i1, i2);
    printf("Derivee : sin en 0 = %.10f\n", d);
    printf("Zero : racine de x*x-2 entre 1 et 2 = %.12f ; sqrt(2) = %.12f ; ecart = %.3e\n",
           z, std::sqrt(2.0), ecart);
    return 0;
}
