// A simple program which calulates factorial of a number from standard input.

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    std::cout << fact << std::endl;
    return 0;
}
