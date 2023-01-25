#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Lol {
    int a, b;
};

int main(){
    struct Lol X;
    X.a = true;
    X.b = 1;
    printf("%d %d\n", X.a, X.b);
    return 0;
}
