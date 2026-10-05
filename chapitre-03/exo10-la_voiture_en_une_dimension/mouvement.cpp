#include<iostream>
#include<iomanip>
double vitesse(double v0, double a, double t){
    return v0 + a * t;
}

double position(double x0, double v0, double a, double t){
    return x0 + v0 * t + 0.5 * a * t * t;
}
int main(){

    double x0, v0, a, t;
    std::cin >>x0 >> v0 >> a >> t;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << vitesse(v0, a, t) << "\n";
    std::cout << position(x0, v0, a, t) << "\n";
    return 0;
}