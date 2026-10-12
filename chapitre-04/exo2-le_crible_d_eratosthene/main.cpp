#include <iostream>
void cribler(bool premier[], int n){
    for (int i = 0; i <= n; i++){
        premier[i] = (i >=2 );
    }
    for (long long i=2; i*i <= n; i++){
       if(premier[i]){
        for(long long j = i*i; j <= n; j+=i){
            premier[j]= false;
        }
       }
    }
}
int main (){
    int n; static bool premier[100001];
    std::cin >> n;
    if(n<2){
        std::cout << "AUCUN\n";
        return 0;
    }
    cribler(premier, n);
    for (int i = 2; i <= n; i++){
        if(premier[1]){
            std::cout << i << "\n";
        }
    }
    return 0;}