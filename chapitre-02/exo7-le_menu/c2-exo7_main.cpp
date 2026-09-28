#include<iostream>
int main(){
    int choix;

    std::cout<<"----MENU----"<<std::endl;
    std::cout<<"1. Nouvelle partie"<<std::endl;
    std::cout<<"2. Charger"<<std::endl;
    std::cout<<"3. Options"<<std::endl;
    std::cout<<"4. Quitter"<<std::endl;
    std::cout<<"Selectionez une option : ";
    std::cin>>choix;

    switch ((choix))
    {
    case 1:
        std::cout<<"-> Nouvelle partie lancee"<<std::endl;
        
    case 2:
        std::cout<<"-> Chargement de la sauvegarde en cours"<<std::endl;
        break;
    case 3:
        std::cout<<"-> Bienvenue dans les options"<<std::endl;
        break;
    case 4:
        std::cout<<"-> Au revoir"<<std::endl;
        break;
    
    default:
        std::cout<<"Choix non disponible"<<std::endl;
        break;
    }
return 0;}