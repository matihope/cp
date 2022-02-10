#include <bits/stdc++.h>

using namespace std;

vector<int> tab, dists;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    dists.assign(n, 0);
    for(int i = 0; i < n; ++i)
        dists[i - 1] = n - i;
    
    tab.assign(n * 2, 0);
    for(int i = 0; i < n; ++i){
        
    }

}