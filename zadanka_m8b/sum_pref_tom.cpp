#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int MAXN = 1e6;
    vector<long long> tab(MAXN, 0);
    vector<long long> pref(MAXN, 0);
    tab[0] = 1;
    pref[0] = 1;
    for(int i = 1; i < MAXN; ++i){
        tab[i] = tab[i - 1] * 2 % MOD;
        pref[i] = pref[i - 1] + tab[i] % MOD;
    }

    int q, n, k;
    cin >> q;
    while(q--){
        cin >> n >> k;
        long long ans = tab[n - 1];
        if(n - k >= 0)
            ans -= pref[n - k];
        ans = (ans + MOD) % MOD;
        cout << ans << endl;
    }
}