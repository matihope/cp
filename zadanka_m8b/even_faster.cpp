#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

long long mul(long long power){
    long long base = 2;
    long long ans = 1;
    while(power){
        if(power & 1)
            ans = ans * base % MOD;
        base = base * base % MOD;
        power /= 2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while(q--){
        long long a, b;
        cin >> a >> b;
        long long p1 = mul(a - 1);
        long long p2 = mul(a - b) - 1;
        cout << p1 - p2 << endl;
    }
}