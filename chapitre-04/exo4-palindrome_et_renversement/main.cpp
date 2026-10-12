#include <cstdio>
int longueurTexte(const char s[]){
    int n = 0;
    while(s[n] != '\0'){
        n++;
    }
    return n;
}
bool estPalindrome(const char s[]){
    int debut = 0;
    int fin = longueurTexte(s) - 1;

    while(debut < fin){
        if (s[debut] != s[fin]){
            return false;
        }
        debut++;
        fin--;
    }
    return true;
}
void renverserTexte(char s[]){
    int debut = 0;
    int fin = longueurTexte(s) - 1;

    while(debut < fin){
        char temp = s[debut];
        s[debut] = s[fin];
        s[fin] = temp;
        debut++;
        fin--;
    }
}
int main(){
    char s[201] = {0};
    std::scanf("%200s", s);
    if(estPalindrome(s)){
        std::printf("oui\n");
    }
    else{
        std::printf("non\n");
    }

    renverserTexte(s);
    std::printf("%s\n", s);
    return 0;
}