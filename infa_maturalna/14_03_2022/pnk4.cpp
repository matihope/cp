#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y, a = 0, b = 0, c = 0;
    for(int i = 0; i < 1000; ++i){
        cin >> x >> y;
        if(x == 5000 || y == 5000){
            b++;
        } else if(x < 5000 && y < 5000) {
            a++;
        } else {
            c++;
        }
    }
    if(b == 9){
        b = 4;
        c += 5;
    }
    cout << a << endl << b << endl << c << endl;
}