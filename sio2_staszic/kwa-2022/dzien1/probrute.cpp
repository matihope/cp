#include <iostream>
#include <vector>

using namespace std;

#define debug(x) { cerr << #x << ": " << x << endl; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, a, b;
    cin >> n >> m >> k;
    vector<vector<bool>> tab(n + 2, vector<bool>(m + 2, 0));
    for(int i = 0; i <= n + 1; ++i){
        tab[i][0] = 1;
        tab[i][m + 1] = 1;
    }
    for(int i = 0; i <= m + 1; ++i){
        tab[0][i] = 1;
        tab[n + 1][i] = 1;
    }
    for(int i = 0; i < k; ++i){
        cin >> a >> b;
        tab[a][b] = true;
    }
    long long counter = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(tab[i][j]) continue;
            int h = 0;
            while(h + i <= n){
                int w = 0;
                if(tab[i + h][j]) continue;
                while(w + j <= m && !tab[i + h][j + 1 + w]) w++;
                // there is a rect
                counter += (h + 1) * (w + 1);
                h++;
            }
        }
    }

    cout << counter << endl;
}