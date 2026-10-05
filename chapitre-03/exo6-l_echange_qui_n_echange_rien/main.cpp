#include<iostream>
void echangerParValeur(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
void echangerParReference(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int a,b;
    std::cin >>a>>b;
    echangerParValeur(a,b);
    std::cout <<a <<"\n" <<b<<"\n";
    echangerParReference(a,b);
    std::cout <<a <<"\n" <<b;
    return 0;}