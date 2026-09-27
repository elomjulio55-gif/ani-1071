#include<iostream>
int main(){
    // cas 1 (1071,462)
    int a,b;
    std::cout<<"Entrer le premier nombre (a)";
    std::cin>>a;
    std::cout<<"Entrer le deuxieme nombre (b)";
    std::cin>>b;

    //ces valeurs seront utilises pour la deuxieme methode
    int a_initial = a;
    int b_initial = b;
    int tours = 0;

    // Methode 1 : soustractions successives
    while(a != b){
        if(a > b){
            a = a-b;
        }else{
            b = b-a;
        }
        tours++;
    }
    std::cout <<"Par la methode de soustraction, le PGCD ( "<< a_initial << "," << b_initial<< ")" << "est egale a" << a << "Ce resultat a ete trouve apres" << tours << "tours." << std::endl;
    // Methode 2 : Divisions successives
    a = a_initial;
    b = b_initial;
    tours = 0;

while (b != 0){
    int reste = a % b;
    a = b;
    b = reste;
    tours++;
}
std::cout <<"Par la methode de divisions, le PGCD(" << a_initial << "," << b_initial << ")" << "est egale a" << a << "Ce resultat a ete trouve apres" << tours << "tours." << std::endl;

return 0;}