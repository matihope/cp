#include <iostream>

using namespace std;

int main() {
    long long x, y;
    long long res = 0;
    cin >> x >> y;
    while (x > y) {
        res += x%2;
        x >>= 1;
        res++;
    }
    if (x != y) {
        x *= 2;
        res += x-y - 1;
    }
    cout << res << endl;
    return 0;
}