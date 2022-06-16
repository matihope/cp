#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
constexpr int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m + 1, 0));
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a == 0){
            if(i == 0){
                for(int j = 1; j <= m; ++j){
                    v[i][j] = 1;
                }
            } else {
                for(int j = 1; j <= m; ++j){
                    v[i][j] = (v[i][j] + v[i - 1][j]) % MOD;
                    if(j + 1 <= m)
                        v[i][j] = (v[i][j] + v[i - 1][j + 1]) % MOD;
                    if(j - 1 >= 1)
                        v[i][j] = (v[i][j] + v[i - 1][j - 1]) % MOD;
                }
            }
        }
        else {
            if(i == 0)
                v[i][a] = 1;
            else{
                v[i][a] = v[i - 1][a];
                if(a + 1 <= m)
                    v[i][a] = (v[i][a] + v[i - 1][a + 1]) % MOD;
                if(a - 1 >= 1)
                    v[i][a] = (v[i][a] + v[i - 1][a - 1]) % MOD;

            }
        }
    }
    LL last_sum = 0;
    for(int i = 1; i <= m; ++i){
        last_sum += v[n - 1][i];
    }
    cout << last_sum % MOD << endl;https://codeforces.com/contests/1697
}
