#include <iostream>
#include <utility>
long long trierParBulles(int t[], int n){
    long long echanges = 0;
    for (int i = 0; i + 1 < n; i++){
        for(int j = 0; j + 1 < n - 1; j++){
            if(t[j] > t[j+1]){
                std::swap(t[j], t[j + 1]);
                echanges++;
            }
        }
    }   
    return echanges; 
}
int main(){
    int n;
    int t[1000];
    std::cin >> n;
    for (int i = 0; i < n; i++){
        std::cin >> t[i];
    }

    long long echanges =trierParBulles(t, n);
    for (int i = 0; i < n; i++){
        std::cout << t[i] << "\n";
    }
    std::cout << echanges << "\n";
    return 0;
}