#include <bits/stdc++.h>

using namespace std;

int rep[251002];
int n, m, k;

int Find(int a){ 
    if(rep[a] == a) return a;
    return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
    rep[Find(b)] = Find(a);
}

pair<int, int> indexes(int x1, int y1, int x2, int y2){
    if(x2 < x1 || y2 > y1){
        swap(x1, x2);
        swap(y1, y2);
    }
    int v1, v2;
    if(x1 == x2){
        // X.
        // ?.
        v1 = (x1 - 1) + (y1 - 1) * (n + 1);
        v2 = v1 + 1;
    }
    else if (y1 == y2){
        // X?
        v1 = x1 + (y1 - 1) * (n + 1);
        v2 = x1 + y1 * (n + 1);
    }
    return {v1, v2};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;
    cin >> n >> m >> k;

    for(int i = 0; i <= (n + 1) * (m + 1); ++i) rep[i] = i;
    // connect horizontally
    for(int i = 0; i < n; i++){
        Union(i, i + 1);
        Union((n + 1) * m + i, (n + 1) * m + 1 + i);
    }
    // connect vertically
    for(int i = 0; i < m; i++){
        Union(i * (n + 1), (i + 1) * (n + 1));
        Union(n + (n + 1) * i, n + (n + 1) * (i + 1));
    }
    for(int i = 0; i < k; ++i){
        cin >> x1 >> y1 >> x2 >> y2;
        auto [v1, v2] = indexes(x1, y1, x2, y2);
        if(Find(v1) != Find(v2)){
            cout << "TAK" << endl;
            Union(v1, v2);
        } else {
            cout << "NIE" << endl;
        }
    }
}