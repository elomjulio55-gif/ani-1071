#include <iostream>
long long fibonacci(int n, long long & appels){
    appels++;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1, appels) + fibonacci(n - 2, appels);
}

int main() {
    int n;
    std::cin >> n;
    long long appels = 0;
    long long resultat = fibonacci(n, appels);
    std::cout << resultat <<"\n" << appels;
    return 0;
}