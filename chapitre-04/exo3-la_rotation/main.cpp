#include <iostream>
void tourner(int t[], int n, int k){
    if (n <= 0){
        return;
    }
    k = k % n;
    if(k < 0){
        k += n;
    }
    int copie[1000];
    for(int i = 0; i < n; i++){
        copie[i] = t[(i + k) % n];
    }
    for(int i = 0; i < n; i++){
        t[i] = copie[i];
    }
}
int main(){
    int n, k;
    int t[1000];

    std::cin >> n >> k;
    for(int i = 0; i < n; i++){
        std::cin >> t[i];
    }
    tourner(t,n, k);
    for(int i = 0; i < n; i++){
        std::cout << t[i] <<"\n";
    }
    return 0;}