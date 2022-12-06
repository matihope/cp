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
    return _sign(t[i]);
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
    int pos = 0, neg = 1;
    if(N != 0){
        while(1){
            while(pos + 1 < 2 * N && (Wartosc(pos) == -1 || (pos % 2 == 1 && Wartosc(pos) == 1)))
                pos++;
            while(neg + 1 < 2 * N && (Wartosc(neg) == 1 || (neg % 2 == 0 && Wartosc(neg) == -1)))
                neg++;
            if(neg == 2 * N - 1 && pos == 2 * N - 1)
                break;
            Zamien(pos, neg);
        }
    }
    // -------------------------------------
    for (int i = 0; i < 2 * N; i++)
        printf("%d ", t[i]);
    printf("\n");
    return 0;
}
