# include<iostream>
int main(){
    long long n;
    std::cout<<"Entrer un entier superieur a 1 (n>1)";
    std::cin>>n;

    //pour verifier la valeur saisie par l'utilisateur
    while( n<=1){
        std::cout<<"Valeur invalide, Entrer un entier superieur a 1 (n>1)";
        std::cin>>n;
    }
    int nbre_transformations = 0;//nombre d'etapes ou de tranformation avant d'atteindre 1
    std::cout<<n;//Pour un affiche sexy
    while (n != 1){
        if(n % 2 ==0){
            n = n/2;
        }else{
            n = 3 * n + 1;
        }
        nbre_transformations++;
        std::cout<<"->"<<n; // A chaque boucle on ajoutera "->" suivie de la nouvelle valeur de n
    }
    std::cout<< std::endl; //Pour un saut a la ligne
    std::cout<<"Le nombre d'etapes est : " << nbre_transformations<< std::endl;
    return 0;}