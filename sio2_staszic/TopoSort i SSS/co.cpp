#include <iostream>

int main(){
    int n, m, a, b;
    std::cin >> n >> m;
    printf("%d_%d_", n, m);
    while(m--){
        std::cin >> a >> b;
        printf("%d_%d_", a, b);
    }
}