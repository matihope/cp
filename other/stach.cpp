#include <iostream>

struct Okno {
    int narysowal = 0;
};

void rysuj(Okno& a){
    a.narysowal++;
}

int main () {
    Okno o;
    rysuj(o);
    std::cout << o.narysowal << std::endl;
    int x;
    std::cin >> x;
    std::cout << x << std::endl;
}
