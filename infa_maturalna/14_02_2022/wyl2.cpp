#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n < 2)
        return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n, a;
    cin >> a;
    for(int i = 0; i < a; ++i){
        cin >> n;
        string b = to_string(n);
        reverse(b.begin(), b.end());
        if(isPrime(n) && isPrime(stoi(b)))
            cout << n << endl;
    }
}