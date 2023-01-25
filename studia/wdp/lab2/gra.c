#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// nwd
int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

// -----------------------------------------------------------------------
// pozycja jest przegrywająca, czyli nie da sie z niej wygrac,
// jesli dla a i b(a i b wzglednie pierwsze) suma a + b jest parzysta
// ---
// checkWin zwraca 1, gdy da sie wygrac z danej pozycji
// i 0 gdy jest to pozycja przegrywajaca
bool checkWin(int a, int b){
    int _gcd = gcd(a, b);
    a /= _gcd;
    b /= _gcd;
    return (a + b) % 2;
}

// jesli a == 1 i b == 1 <=> koniec gry  => return 0
// jesli nalezy zrobic a - 1, aby wygrac => return 1
// jesli nalezy zrobic b - 1, aby wygrac => return 2
// jesli nie da sie wygrac, to zwroc 1 lub 2 tak, aby dalej sie dalo grac
int graj(int a, int b){
    int _gcd = gcd(a, b);
    a /= _gcd;
    b /= _gcd;
    if(a == b && b == 1)
        return 0;

    if(a - 1 >= 1 && !checkWin(a - 1, b))
        return 1;
    if(b - 1 >= 1 && !checkWin(a, b - 1))
        return 2;
        
    if(a - 1 >= 1)
        return 1;
    else
        return 2;
}
