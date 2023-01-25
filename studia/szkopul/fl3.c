#include <stdio.h>
#include <stdlib.h>
void _zakres(int i, char *is, int M, char *funkcja)
{
    if (!(0 <= i && i < M))
    {
        fprintf(stderr, "Przekroczenie zakresu w %s: argument %s to %d, miało być 0 <= %s < %d\n",
                funkcja, is, i, is, M);
        exit(1);
    }
}

int _sign(int a){
    if(a < 0) return -1;
    return 1;
}

int _wartosc(int i, int t[], int N)
{
    _zakres(i, "i", 2 * N, "Wartosc");
    return t[i];
}
void _zamien(int i, int j, int t[], int N)
{
    _zakres(i, "i", 2 * N, "Zamien");
    _zakres(j, "j", 2 * N, "Zamien");
    int tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
}
int main()
{
    int N;
    scanf("%d", &N);
    int t[2 * N];
    for (int i = 0; i < 2 * N; i++)
        scanf("%d", &t[i]);
    #define Wartosc(i) _wartosc(i, t, N)
    #define Zamien(i, j) _zamien(i, j, t, N)
    // Mamy ustalone N i zawartość urn
    // -------------------------------------
    // Poniżej wpisz swój fragment programu:
    if(N != 0){
        int pos = 0, neg = 1;
        while(1){
            while(pos + 1 < 2 * N && (_sign(Wartosc(pos)) == -1 || (pos % 2 == 1 && _sign(Wartosc(pos)) == 1)))
                pos++;
            while(neg + 1 < 2 * N && (_sign(Wartosc(neg)) == 1 || (neg % 2 == 0 && _sign(Wartosc(neg)) == -1)))
                neg++;
            if(neg == 2 * N - 1 && pos == 2 * N - 1)
                break;
            Zamien(pos, neg);
        }
        int num_not_zero = 1, zero = 1;
        while(zero < N * 2 && num_not_zero < N * 2) {
            while(num_not_zero + 1 < N * 2 && Wartosc(num_not_zero) <= 0)
                num_not_zero++;
            while(zero + 1 < N * 2 && Wartosc(zero) != 0)
                zero++;
            if(Wartosc(num_not_zero) <= 0 || Wartosc(zero) != 0)
                break;
            if(num_not_zero < zero)
                Zamien(zero, num_not_zero);
            else
                zero++;
        }
    }
    // -------------------------------------
    for (int i = 0; i < 2 * N; i++)
        printf("%d ", t[i]);
    printf("\n");
    return 0;
}
