#include<iostream>
int nombreDeChiffres(int n){
    long long v = n;
    if(v < 0) v = -v;
    if(v == 0) return 1;

    int compte = 0;
    while(v > 0){
        v = v/10;
        compte++;
    }
    return compte;
}
int main(){
    int n;
    int lus = 0;
    while(std::cin >> n){
        std::cout << nombreDeChiffres(n)<<"\n";
        lus++;
    }
    if(lus == 0){
        std::cout<<"AUCUN\n";
    }
    return 0;}