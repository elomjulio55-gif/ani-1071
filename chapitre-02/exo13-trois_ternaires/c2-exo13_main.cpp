#include<iostream>
int main(){
    int a , b;
    std::cout <<"Entrer un premier nombre";
    std::cin>>a;
    std::cout <<"Entrer un deuxieme nombre";
    std::cin>>b;

    // 1. premier terniaire: plus petit
    std::cout<<(a < b ? a:b)<<std::endl;
    // 2. deuxieme terniaire: plus grand
    std::cout<<(a < b ? b:a)<<std::endl;
    // 3. troisieme terniaire: parite du premier entier(a)
    std::cout<<(a % 2 == 0 ? "pair": "impair")<<std::endl;
    // 4. Cas des accords a partir du deuxieme entier(b)
    std::cout<<b <<(b>1 ? "objets": "objet")<<std::endl;

return 0;}