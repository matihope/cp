#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, a, l, d;
    cin >> n >> k;
    vector<int> tab(n, 0);
    int sqr = ceil(sqrt(n));
    vector<vector<int>> adds(ceil(sqrt(n)), vector<int>(n, 0));
    while(k--){
        cin >> a >> l >> d;
        if(d >= sqr){
            for(int i = 0; i < l; i++)
                ++tab[a + i*d - 1]; 
        } else {
            ++adds[d][a - 1];
            if(a + (l) * d - 1 < n)
                --adds[d][a + (l) * d - 1];
        }
    }
    for(int i = 1; i < sqr; i++){
        for(int j = 0; j < n; ++j){
            if(j - i >= 0)
                adds[i][j] += adds[i][j - i];
            tab[j] += adds[i][j];
        }
    }
    for(int j = 0; j < n; ++j)
        cout << tab[j] << " ";
}