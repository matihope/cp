#include <iostream>
#include <vector>

using namespace std;

#define INF_I 1000000001
#define INF_LL 1000000000000000001
typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    VI tab(m + 1, INF_I);
    VI coins(n);
    for(int i = 0; i < n; ++i)
        cin >> coins[i];
    
    tab[0] = 0;
    for(int i = 0; i <= m; ++i){
        for(auto& coin: coins){
            if(i + coin <= m)
                tab[i + coin] = min(tab[i + coin], tab[i] + 1); 
        }
    }
    cout << (tab[m] == INF_I ? -1 : tab[m]) << endl;

}