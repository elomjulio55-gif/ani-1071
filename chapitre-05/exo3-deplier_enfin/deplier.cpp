#include <cstdio>

void deplier(int i, int largeur, int x, int& y){
    x = i % largeur;
    y = i / largeur;
}

void minMax(const int t[], int n, int& min, int& max){
    min = t[0];
    max = t[0];
    for (int k = 1; k <n; k++){
        if (t[k] < min){
            min = t[k];
        }
        if (t[k] > max){
            max = t[k];
        }
    }
}

bool diviser(int a, int b, int& quotient, int& reste){
    if(b==0){
        return false;
    }
    quotient = a / b;
    reste = a % b;
    return true;
}

int main(){
    printf("deplier :\n");
    int numeros[] = {0, 39 ,40, 85};
    for ( int k = 0; k < 4; k++){
        int x, y;
        deplier(numeros[k], 40, x, y);
        printf("i =%d largeur = 40 -> x=%d y=%d\n", numeros[k], x, y);
    }

    printf("\nminMax :\n");
    int t1[]= {12, 7, 19, 3, 15};
    int t2[]= {-5, -2, -9};
    int mn, mx;
    minMax(t1, 5, mn ,mx);
    printf("t={12, 7, 19, 3, 15} n=5 -> min=%d\n", mn, mx);
    minMax(t2, 3, mn, mx);
    printf("t={-5, -2, -9} n=3 -> min=%d\n", mn, mx);

    printf("\ndiviser :\n");
    int q, r;
    bool ok = diviser(17 ,5, q, r);
    printf("a=17 b=5 -> rendu=%d quotient=%d reste\n", ok, q, r);
    ok = diviser(100, 7 , q , r);
    printf("a=100 b=7 -> rendu=%d quotient=%d reste\n", ok, q, r);

    printf("\nPar zero :\n");
    q = -999;
    r = -999;
    printf ("avant : quotient=%d reste=%d\n", q, r);
    ok = diviser(10, 0 , q, r);
    printf("valeur rendue : %d(0 = false)\n", ok);
    printf ("apres : quotient=%d reste=%d\n", q, r);
    return 0;
}