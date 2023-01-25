#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    vector<vector<int>> tab(a.size() + 1, vector<int>(b.size() + 1, 0));

    for(size_t i = 1; i <= a.size(); ++i) {
        for(size_t j = 1; j <= b.size(); ++j) {
            tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            if(a[i - 1] == b[j - 1])
                tab[i][j]++;
        }
    }

    int x = (int)a.size();
    int y = (int)b.size();
    string ans;
    while(y > 0 && x > 0) {
        if(tab[x][y] == tab[x][y - 1])
            y--;
        else if(tab[x][y] == tab[x - 1][y])
            x--;
        else {
            ans = (char)a[x - 1] + ans;
            y--;
            x--;
        }
    }
    cout << ans << endl;
    int replace = min(a.size(), b.size()) - ans.size();
    int to_add = abs((int)a.size() - (int)b.size());
    cout << replace + to_add << endl;
}
