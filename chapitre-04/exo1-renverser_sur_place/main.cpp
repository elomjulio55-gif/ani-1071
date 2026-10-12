#include <iostream>
#include <utility>
void renverser(int t[], int n){
    for(int i=0; i< n /2 ; i++){
        std::swap(t[i], t[n - 1 -i]);
    }
}
int main(){
    int n;
    int t[1000];

    std::cin >> n;
    if(n <= 0){
        std::cout << "AUCUN\n";
        return 0;
    }
    for (int i =0; i <n; i++){
        std::cin >> t[i];
    }
    renverser(t, n);
    for (int i =0; i <n; i++){
        std::cout << t[i] << "\n";
    }
    return 0;
}