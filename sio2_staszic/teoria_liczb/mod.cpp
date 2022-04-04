#include <bits/stdc++.h>

using namespace std;

long long pow(long long a, long long b, int mod){
    long long ans = 1, now = a;
    for(int i = 0; i < 32; i++){
        if((1 << i) & b)
            ans = ans * now % mod;
        now = now * now % mod;
    }
    return ans;
}

long long fact(long long a, int mod){
    if(a == 1) return a;
    return a * fact(a - 1, mod) % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;
    cout << fact(n + m, p) * pow(fact(n, p) * fact(m, p) % p, p - 2, p) % p << endl;
}