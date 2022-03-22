#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int counter = 0, x, y;
    for(int i = 0; i < 1000; ++i){
        cin >> x >> y;
        if(isPrime(x) && isPrime(y))
            counter++;
    }
    cout << counter << endl;
}