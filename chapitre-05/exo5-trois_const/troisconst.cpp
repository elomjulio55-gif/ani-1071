#include <cstdio>

int main() {
    int x = 1, y = 2;
    const int* a = &x;
    int* const b = &x;
    const int* const c = &x;

    // a
    a = &y;
    // b
    *b = 5;
    printf("%d %d %d %d %d\n", x, y, *a, *b, *c);
    return 0;
}
