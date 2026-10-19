#include <cstdio>

char* creerImage(int l, int h) {
    char* img = new char[l * h];
    for (int k = 0; k < l * h; k++) {
        img[k] = ' ';
    }
    return img;
}

void detruireImage(char* img) {
    delete[] img;
}

void point(char* img, int l, int h, int x, int y, char c) {
    if (x < 0 || x >= l || y < 0 || y >= h) {
        return;
    }
    img[y * l + x] = c;
}

void afficher(const char* img, int l, int h) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < l; x++) {
            std::putchar(img[y * l + x]);
        }
        std::putchar('\n');
    }
}

void dessinerCercle(char* img, int l, int h) {
    double cx = (l - 1) / 2.0;     
    double cy = (h - 1) / 2.0;
    double r = h / 2.0 - 1;        
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < l; x++) {
            double dx = x - cx;
            double dy = y - cy;
            if (dx * dx + dy * dy <= r * r) {
                point(img, l, h, x, y, '#');
            }
        }
    }
}

int main() {
    char* petite = creerImage(30, 10);
    dessinerCercle(petite, 30, 10);
    afficher(petite, 30, 10);
    detruireImage(petite);

    char* grande = creerImage(80, 24);
    dessinerCercle(grande, 80, 24);
    afficher(grande, 80, 24);
    detruireImage(grande);
    return 0;
}
