#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n <= 100 || n > 5000)
        return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    for(int i = 0; i < 300; ++i){
        cin >> n;
        if(isPrime(n))
            cout << n << endl;
    }
}