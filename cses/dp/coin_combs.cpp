#include <iostream>
#include <vector>
 
using namespace std;

typedef long long LL;
typedef vector<int> VI;
constexpr int MOD = 1e9 + 7;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    VI tab(m + 1, 0);
    VI coins(n);
    for(int i = 0; i < n; ++i){
        cin >> coins[i];
        if(coins[i] <= m)
            tab[coins[i]] = 1;
    }
    
    tab[0] = 0;
    for(int i = 0; i <= m; ++i){
        if(tab[i] != 0)
            for(auto& coin: coins)
                if(i + coin <= m)
                    tab[i + coin] = (tab[i + coin] + tab[i]) % MOD; 
    }
    cout << tab[m] << endl;
 
}