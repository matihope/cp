#define _CRT_SECURE_NO_WARNINGS

#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct tekst {
    int ilosc_znakow;
    char *napis;
} tekst;

void wyswietl_tekst(char *T[], int ilosc_wierszy);
void tekst_na_strukture(char *T[], int ilosc_wierszy);
void oczysc_tekst(tekst *T, char *znaki_do_usuniecia);
void na_male(tekst *T);
void dwuznaki(tekst *T, char *DW, char z);

int main(void) {
    unsigned int ilosc_wierszy = 0;
    char *znaki_do_usuniecia = ".,!@#$%^&*()-+—_?<>:;'%%\"\\/–\n";
    tekst *T_0;

    char *azazel[] = {"Azazel - Boris Akunin",
                      "___________________",
                      "Rozdział pierwszy,",
                      "w którym opisany jest pewien cyniczny wybryk.",
                      "W poniedziałek trzynastego maja 1876 roku o trzeciej po "
                      "południu, w dzień po",
                      "wiosennemu świeży i po letniemu ciepły, wiele osób w "
                      "parku Aleksandrowskim stało się",
                      "świadkami skandalicznego zdarzenia, którego niczyja "
                      "wyobraźnia nie mogła przewidzieć.",
                      "Alejami, pośród kwitnących bzów i pałających czerwonymi "
                      "tulipanami klombów,",
                      "przechadzało się szykowne towarzystwo: panie pod "
                      "koronkowymi parasolkami (żeby nie",
                      "dostać piegów), bony z dziećmi w marynarskich "
                      "ubrankach, znudzeni młodzi ludzie w",
                      "modnych szewiotowych surdutach albo na angielską modłę "
                      "krótkich marynarkach. Nic nie",
                      "zapowiadało, że wydarzy się coś przykrego; powietrze, "
                      "pełne aromatów dojrzałej, pewnej",
                      "siebie wiosny, sprzyjało nastrojowi leniwego "
                      "zadowolenia i pogodnej nudy. Słońce",
                      "przypiekało nie na żarty, toteż wszystkie pozostające w "
                      "cieniu ławki były zajęte."};

    setlocale(LC_ALL, "");  // polskie znaki w konsoli

    ilosc_wierszy = sizeof(azazel) / sizeof(char *);
    printf("%d", ilosc_wierszy);

    // Etap 1
    printf("--------------");
    printf("\n--==ETAP 1==--\n");
    printf("--------------\n\n");
    wyswietl_tekst(azazel, ilosc_wierszy);

    ////Etap 2
    printf("\n--------------");
    printf("\n--==ETAP 2==--\n");
    printf("--------------");
    // T_0 =
    tekst_na_strukture(azazel, ilosc_wierszy);
    // printf("\n\n%s\n", T_0->napis);
    // printf("\nIlość znaków: %d", T_0->ilosc_znakow);

    ////Etap 3
    // printf("\n\n--------------");
    // printf("\n--==ETAP 3==--\n");
    // printf("--------------");
    // na_male(T_0);
    // oczysc_tekst(T_0, znaki_do_usuniecia);
    // printf("\n\n%s\n", T_0->napis);
    // printf("\nIlość znaków: %d", T_0->ilosc_znakow);

    ////Etap 4
    // printf("\n\n--------------");
    // printf("\n--==ETAP 4==--\n");
    // printf("--------------");
    // dwuznaki(T_0, "rz", 'ż');
    // dwuznaki(T_0, "sz", 'S');
    // dwuznaki(T_0, "cz", 'C');
    // dwuznaki(T_0, "dz", 'D');
    // dwuznaki(T_0, "ch", 'h');
    // printf("\n\n%s\n", T_0->napis);
    // printf("\nIlość znaków: %d", T_0->ilosc_znakow);

    free(T_0);
    printf("\n\n");
    system("pause");
    return 0;
}
void wyswietl_tekst(char *T[], int w) {
    int i;
    for (i = 0; i < w; i++) {
        printf("%s\n", T[i]);
    }
}
void tekst_na_strukture(char *T[], int w) {
    int mal = 0;
    int i, j, m;
    // tekst* wynik;
    for (i = 0; i <= strlen(T[2]); i++) {
        printf("%c %d %d\n", T[2][i], T[2][i], i + 1);
    }
}
