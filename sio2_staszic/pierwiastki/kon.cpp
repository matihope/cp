#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a, l, d;
    cin >> n >> k;
    int sqrt_n = ceil(sqrt(n));
    vector<vector<int>> sq(sqrt_n + 1, vector<int>(n + 1, 0));
    vector<int> tab(n + 1, 0);
    while(k--){
        cin >> a >> l >> d;
        if(d <= sqrt_n){
            sq[d][a]++;
            if(a + d * l <= n)
                sq[d][a + d * l]--;
        } else {
            for(int i = 0; i < l; ++i)
                tab[a + i * d]++;
        }
        
    }
    for(int t = 1; t <= n; ++t){
        for(int i = 1; i <= sqrt_n; ++i) {
            if(t - i >= 0){
                sq[i][t] += sq[i][t - i];
            }
            tab[t] += sq[i][t];
        }
        cout << tab[t] << " ";
    }
}