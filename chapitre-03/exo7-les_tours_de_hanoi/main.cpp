#include <iostream>
void hanoi (int n, char depart, char arrivee, char intermediaire){
    if(n <= 0 ){
        return;
    }
    hanoi(n-1, depart, intermediaire, arrivee);
    std::cout <<depart << ">" << arrivee << "\n";
    hanoi(n-1, intermediaire, arrivee, depart);
}
int main (){
    int n;
    std::cin >> n;
    hanoi(n, 'A', 'C', 'B');
    long long total = 0;
    if(n>0){
        total = (1LL << n ) - 1;
    }
    std::cout << total;
    return 0;}