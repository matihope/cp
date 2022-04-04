#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        vector<long long> tab(n + 1);
        tab[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = max(i - k, 0); j < i; ++j){
                tab[i] += tab[j] % MOD;
            }
        }
        cout << tab[n] << endl;
    }
}