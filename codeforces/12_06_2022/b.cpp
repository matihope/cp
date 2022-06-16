#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<LL> tab(n);
    vector<LL> prefsum(n + 1, 0);
    for(int i = 0; i < n; ++i){
        cin >> tab[i];
    }
    sort(tab.begin(), tab.end(), [&](const LL& a, const LL& b){ return a > b; });
    for(int i = 0; i < n; ++i)
        prefsum[i + 1] = prefsum[i] + tab[i];

    while(q--){
        LL x, y;
        cin >> x >> y;
        cout << prefsum[x] - prefsum[x - y] << endl;
    }
}
