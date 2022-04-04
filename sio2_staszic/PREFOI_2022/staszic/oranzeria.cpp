#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, q;
    cin >> n >> m >> k;
    vector<vector<vector<long long>>> tab(k + 1, vector<vector<long long>>(m + 1, vector<long long>(n + 1, 0)));
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= m; ++j){
            for(int b = 1; b <= n; ++b){
                cin >> tab[i][j][b];
                tab[i][j][b] += tab[i - 1][j][b];
                tab[i][j][b] += tab[i][j][b - 1] - tab[i - 1][j][b - 1];
                tab[i][j][b] += tab[i][j - 1][b] - tab[i - 1][j - 1][b];
                tab[i][j][b] -= tab[i][j - 1][b - 1];
                tab[i][j][b] += tab[i - 1][j - 1][b - 1];
            }
        }
    }
    cin >> q;
    int n1, n2, m1, m2, k1, k2;
    while(q--){
        cin >> n1 >> n2 >> m1 >> m2 >> k1 >> k2;
        long long ans = tab[k2][m2][n2];
        ans -= tab[k1 - 1][m2][n2];
        ans -= tab[k2][m1 - 1][n2];
        ans -= tab[k2][m2][n1 - 1];
        ans += tab[k1 - 1][m2][n1 - 1];
        ans += tab[k1 - 1][m1 - 1][n2];
        ans += tab[k2][m1 - 1][n1 - 1];
        ans -= tab[k1 - 1][m1 - 1][n1 - 1];
        cout << ans << endl;
    }
}