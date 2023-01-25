// Mateusz Kolpa
// Graj w gre z lab2

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "gra.h"

// kolory dla kolorowego outputu
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(){
    int a, b;
    printf("Wczytaj początkowe liczby a i b: ");
    scanf("%d", &a);
    scanf("%d", &b);

    bool ruch_gracza = true;
    while(graj(a, b) != 0){
        int ruch;

        // zdobadz dane do ruchu
        if(ruch_gracza){
            printf("\nOd ktorej liczby nalezy odjac? [1/2] ");
            scanf("%d", &ruch);
        } else {
            printf("\nRuch komputera...");
            ruch = graj(a, b);
        }

        // ewaluacja ruchu
        if(ruch == 1)
            a--;
        else
            b--;

        int _gcd = gcd(a, b);
        a /= _gcd;
        b /= _gcd;
        printf("\nAktualny stan: a = %d, b = %d", a, b);
        ruch_gracza = !ruch_gracza;

    }

    printf("\nWygrywa %s\n"ANSI_COLOR_RESET, (ruch_gracza ? ANSI_COLOR_RED"komputer" : ANSI_COLOR_GREEN"gracz"));
}
