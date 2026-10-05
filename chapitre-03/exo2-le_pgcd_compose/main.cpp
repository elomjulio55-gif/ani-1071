#include <iostream>
long long pgcd(long long a, long long b){
    if (a<0){
        a = -a;
    }
    if (b<0){
        b = -b;
    }
    while(b != 0){
        long long reste = a % b;
        a =b;
        b = reste;
    }
    return a;
}
long long ppcm(long long a, long long b){
    if (a == 0 || b == 0){
        return 0;
    }
    if (b<0){
        b = -b;
    }
    if (a<0){
        a = -a;
    }
    return a /pgcd(a,b) * b;
}
int main(){
    long long a, b;
    int lus = 0;
        while(std::cin >> a>> b){
        std::cout << pgcd(a,b)<<"\n";
        std::cout << ppcm(a,b)<<"\n";
        lus++;
    }
    if(lus == 0){
        std::cout<<"AUCUN\n";
    }
    return 0;}