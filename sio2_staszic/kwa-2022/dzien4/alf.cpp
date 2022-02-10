#include <bits/stdc++.h>

using namespace std;

#define INF 200000

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;
    vector<vector<int>> lines_that_assure(n, vector<int>(l + 1, INF));
    vector<string> tab(n);
    int x = 1, len = 20001;
    for(int i = 0; i < n; ++i) cin >> tab[i];

    for(int i = l - 1; i >= 0; --i) {
        char prev = tab[n - 1][i];
        int curr_len = 0;
        for(int j = n - 2; j >= 0; --j) {
            if(tab[j + 1][i] > tab[j][i])
                lines_that_assure[j][i] = 1;
            else if(tab[j + 1][i] == tab[j][i])
                lines_that_assure[j][i] = lines_that_assure[j][i + 1] + 1;
            curr_len = max(curr_len, lines_that_assure[j][i]);
            prev = tab[j][i];
        }
        if(curr_len < len){
            x = i + 1;
            len = curr_len;
        }
    }
        
    cout << x << " " << x + len - 1 << endl;
}