#include <iostream>
#include <cstring>

int n;
int* &funA(int**&);
void funB(int*, int**,int**);

int main() {
    int a[100], b[100], c[100];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    int **p = nullptr;
    int **q = nullptr;
    funA(p) = a;
    funA(q) = b;
    funB(c, p, q);
    for (int i = 0; i < n; ++i) {
        std::cout << c[i] << " ";
    }
    delete p;
    delete q;
    return 0;
}

int* &funA(int**& x) {
    x = new int*;
    return *x;
}

void funB(int* c, int** p, int** q) {
    for (int i = 0; i < n; ++i) {
        *(c + i) = *(*p + i) * *(*q + i);
    }
}