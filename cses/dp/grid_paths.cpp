#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
constexpr int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<string> board(n);
    vector<VLL> tab(n + 1, VLL(n + 1, 0));
    tab[1][1] = 1;
    for(int i = 1; i <= n; ++i){
        cin >> board[i - 1];
        for(int j = 1; j <= n; ++j){
            if(board[i - 1][j - 1] == '*')
                continue;
            tab[i][j] = (tab[i][j] + tab[i][j - 1]) % MOD;
            tab[i][j] = (tab[i][j] + tab[i - 1][j]) % MOD;
        }
    }
    if(board[0][0] != '*')
        cout << tab[n][n] << endl;
    else
        cout << 0 << endl;
}