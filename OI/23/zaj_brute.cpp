#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<int> prev_a(n), prev_b(m);
    unordered_map<int, int> map_a, map_b;
    for(int i = 0; i < n; i++) { 
        cin >> a[i];
        prev_a[i] = map_a[a[i]];
        map_a[a[i]] = i + 1;
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        prev_b[i] = map_b[b[i]];
        map_b[b[i]] = i + 1;
    }
    
    vector<vector<int>> tab(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i - 1] == b[j - 1] && prev_a[i - 1] > 0 && prev_b[j - 1] > 0)
                tab[i][j] = tab[prev_a[i - 1] - 1][prev_b[j - 1] - 1] + 2;
            
            tab[i][j] = max(tab[i - 1][j], max(tab[i][j - 1], tab[i][j]));
        }
    }
    cout << tab[n][m] << endl;
}
