#include <cstdio>
#include <cstdlib>
#include <cstring>

long long compteurRapide = 0;
long long compteurSelection = 0;
bool pivotAuMilieu = false;

void echanger(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void triSelection(int t[], int n) {
    for (int pos = 0; pos < n - 1; pos++) {
        int plusPetit = pos;
        for (int j = pos + 1; j < n; j++) {
            compteurSelection++;                 
            if (t[j] < t[plusPetit]) plusPetit = j;
        }
        echanger(t[pos], t[plusPetit]);
    }
}

void triRapide(int t[], int bas, int haut) {
    if (bas >= haut) return;                     
    if (pivotAuMilieu) echanger(t[(bas + haut) / 2], t[haut]);  
    int pivot = t[haut];
    int i = bas;
    for (int j = bas; j < haut; j++) {
        compteurRapide++;                        
        if (t[j] < pivot) {
            echanger(t[i], t[j]);
            i++;
        }
    }
    echanger(t[i], t[haut]);                     
    triRapide(t, bas, i - 1);                    
    triRapide(t, i + 1, haut);                   
}

bool estTrie(const int t[], int n) {
    for (int k = 1; k < n; k++) {
        if (t[k - 1] > t[k]) return false;
    }
    return true;
}

void mesureAleatoire(int n) {
    int* a = new int[n];
    int* b = new int[n];
    for (int k = 0; k < n; k++) {
        a[k] = std::rand();
        b[k] = a[k];                           
    }
    compteurSelection = 0;
    compteurRapide = 0;
    triSelection(a, n);
    triRapide(b, 0, n - 1);

    bool juste = estTrie(a, n) && estTrie(b, n);
    for (int k = 0; k < n; k++) {
        if (a[k] != b[k]) juste = false;        
    }
    printf("%d : tri rapide = %lld ; selection = %lld\n", n, compteurRapide, compteurSelection);
    if (!juste) printf("ERREUR : un des tris est faux pour n = %d\n", n);

    delete[] a;
    delete[] b;
}

void mesureTrie(int n, bool milieu) {
    int* t = new int[n];
    for (int k = 0; k < n; k++) t[k] = k;
    pivotAuMilieu = milieu;
    compteurRapide = 0;
    triRapide(t, 0, n - 1);
    printf("deja trie, n = %d, pivot %s : tri rapide = %lld\n",
           n, milieu ? "au milieu" : "au bout", compteurRapide);
    if (!estTrie(t, n)) printf("ERREUR : le tableau n'est pas trie\n");
    delete[] t;
}

int main(int argc, char* argv[]) {
    if (argc >= 3 && std::strcmp(argv[1], "trie") == 0) {
        
        int n = std::atoi(argv[2]);
        bool milieu = (argc >= 4 && std::strcmp(argv[3], "milieu") == 0);
        mesureTrie(n, milieu);
    } else {
        int tailles[] = {100, 1000, 10000, 100000};
        for (int k = 0; k < 4; k++) mesureAleatoire(tailles[k]);
    }
    return 0;
}