#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define OUTPUT_SIZE 20


// nwd
int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b % a, a);
}


bool checkWin(int a, int b){
    int _gcd = gcd(a, b);
    a /= _gcd;
    b /= _gcd;
    return (a - 1 == 1 && b == 1) || (a == 1 && b - 1 == 1);
}

// zwraca 1 jesli gracz moze wygrac z danej pozycji
// 0 jesli nie moze
bool czyMoznaWygrac(int a, int b){
    int _gcd = gcd(a, b);
    a /= _gcd;
    b /= _gcd;
    if(checkWin(a, b))
        return 1;

    int graj_a = -1;
    if(a - 1 >= 1)
        graj_a = !czyMoznaWygrac(a - 1, b);
    int graj_b = - 1;
    if(b - 1 >= 1)
        graj_b = !czyMoznaWygrac(a, b - 1);
    if(graj_a == 1 || graj_b == 1)
        return true;
    return false;
}

int graj(int a, int b){
    int _gcd = gcd(a, b);
    a /= _gcd;
    b /= _gcd;
    if(a == b && b == 1)
        return 0;

    if(a - 1 >= 1 && !czyMoznaWygrac(a - 1, b))
        return 1;
    if(b - 1 >= 1 && !czyMoznaWygrac(a, b - 1))
        return 2;
    return 3;
}

int main(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("i\\j\t");
    for(int j = 1; j <= OUTPUT_SIZE; ++j)
        printf("%d\t", j);
    printf("\n");

    for(int i = 1; i <= OUTPUT_SIZE; ++i){
        printf("%d\t", i);
        for(int j = 1; j <= OUTPUT_SIZE; ++j){
            int x = graj(i, j);
            if(x == 1)
                printf(ANSI_COLOR_YELLOW);
            if(x == 2)
                printf(ANSI_COLOR_YELLOW);
            if(x == 3)
                printf(ANSI_COLOR_RED);
            printf("%d\t", graj(i, j));
            printf(ANSI_COLOR_RESET);
        }
        printf("\n");
    }
}
