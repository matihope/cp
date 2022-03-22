#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y, a;
    cin >> n >> m >> x >> y;
    int maxi = -101, mini = 101;
    for(int i = 0; i < n; ++i){
        cin >> a;
        maxi = max(maxi, a);
    }
    for(int i = 0; i < m; ++i){
        cin >> a;
        mini = min(mini, a);
    }
    if(maxi < y && maxi < mini && mini > maxi && mini > x){
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }
}