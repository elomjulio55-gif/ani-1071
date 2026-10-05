#include <iostream>
int chiffresRecursif(int n){
    if (n<10){
        return 1;
    }
    
}

int sommeChiffresRecursif(int n) {
    if(n == 0) {
        return 0;
    }
    return n % 10 + sommeChiffresRecursif(n / 10);
}
 int main() {
    int n;
    int lus = 0;
    while(std::cin >>n){
        long long v=n;
        if(v<0){
            v = -v;
        }
        int absolu = int(v);
        std::cout << chiffresRecursif(absolu) << "\n";
        std::cout << sommeChiffresRecursif(absolu) << "\n";
        lus++;

    }
    if(lus == 0){
        std::cout <<"Aucun\n";
    }
    return 0;}