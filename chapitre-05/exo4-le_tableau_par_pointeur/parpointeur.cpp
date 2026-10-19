#include <cstdio>
#include <cstring>

// Somme des n cases 
int somme(const int* t, int n) {
    int total = 0;
    for (const int* p = t; p < t + n; p++) {
        total += *p;
    }
    return total;
}

// Plus grande valeur 
int maximum(const int* t, int n) {
    int grand = *t;
    for (const int* p = t + 1; p < t + n; p++) {
        if (*p > grand) {
            grand = *p;
        }
    }
    return grand;
}

void inverser(int* t, int n) {
    int* debut = t;
    int* fin = t + n - 1;
    while (debut < fin) {
        int tmp = *debut;
        *debut = *fin;
        *fin = tmp;
        debut++;
        fin--;
    }
}

int longueur(const char* s) {
    const char* p = s;
    while (*p != '\0') {
        p++;
    }
    return p - s;
}

int main() {
    int t1[] = {12, 7, 19, 3, 15};
    printf("somme = %d\n", somme(t1, 5));
    printf("maximum = %d\n", maximum(t1, 5));

    int t2[] = {1, 2, 3, 4, 5};
    printf("inverser : ");
    for (int k = 0; k < 5; k++) printf("%d ", t2[k]);
    inverser(t2, 5);
    printf("-> ");
    for (int k = 0; k < 5; k++) printf("%d ", t2[k]);
    printf("\n");

    printf("longueur(\"bonjour\") = %d ; strlen = %d\n", longueur("bonjour"), (int)std::strlen("bonjour"));
    printf("longueur(\"Yaoundé\") = %d ; strlen = %d\n", longueur("Yaoundé"), (int)std::strlen("Yaoundé"));
    return 0;
}
