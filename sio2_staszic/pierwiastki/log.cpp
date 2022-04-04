#include <bits/stdc++.h>

using namespace std;

long long pow(int a, int power, int mod){
    long long result = 1;
    long long now = a;
    for(int i = 0; i < 32; ++i){
        if((1<<i) & power)
            result = result * now % mod;
        now = now * now % mod;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, c, p;
    while(cin >> a >> c >> p){
        for(int i = 0; i <= 100; ++i){
            if(pow(a, i, p) == c){
                cout << i << endl;
            }
        }
    }
}