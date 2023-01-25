#include <stdlib.h>
#include <stdio.h>

#define LL long long
#define N 10

LL koduj(int a, int b){
    LL pow = 0;
    LL sum = 1;
    while(sum < a || sum < b){
        sum *= 10;
        pow++;
    }
    LL space = 1;
    for(int i = 0; i < pow; ++i)
        space *= 10;
    space += a;
    for(int i = 0; i < pow; ++i)
        space *= 10;
    space += b;
    return space;
}

int parse_size(LL num){
    int s = 1;
    while(num){
        s++;
        num /= 10;
    }
    return (s - 1) / 2;
}

LL decode_a(LL num) {
    int s = parse_size(num);
    int sub = 1;
    for(int i = 0; i < s; ++i){
        num /= 10;
        sub *= 10;
    }
    return num - sub;
}

LL decode_b(LL num){
    int s = parse_size(num);
    int sub = 1, sub2 = 1;
    for(int i = 0; i < s * 2; ++i)
        sub *= 10;
    for(int i = 0; i < s; ++i)
        sub2 *= 10;
    return num - sub - decode_a(num) * sub2;
}

int main(){
    int a = 5;
    int b = 2005;
    LL num = koduj(a, b);
    printf("%d\n", num);
    printf("A: %d\n", decode_a(num));
    printf("B: %d\n", decode_b(num));
    return 0;
}
