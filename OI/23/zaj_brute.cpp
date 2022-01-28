#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    queue<int> ans;
    // while(1){
    //     cin >> a;
    //     if(a == -1) break;
    //     ans.push(a);
    // }
    int n, m;
    cin >> n >> m;
    vector<int> s1(n), s2(m);
    for(auto& i: s1) cin >> i;
    for(auto& i: s2) cin >> i;

    vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s1[i - 1] == s2[j - 1]){
                v[j][i] = v[j - 1][i - 1] + 1;
            }
            else 
                v[j][i] = max(v[j - 1][i], v[j][i - 1]);
        }
    }
    int v_pos = m;
    int s_pos = n - 1;
    int i = m, j = n;
    while(v[i][j] > 0){
        if(v[i][j] != v[i][j - 1] && v[i][j] != v[i - 1][j]){
            ans.push(s2[--i]);
            j--;
        } else if(v[i][j] == v[i][j - 1]){
            j--;
        } else{
            i--;
        }
    }
    set<int> res;
    int counter = 0;
    res.insert(ans.front());
    ans.pop();
    while(!ans.empty()){
        int now = ans.front();
        ans.pop();
        if(res.count(now) > 0){
            counter += 2;
            cout << now << " " << now << " "; 
            res.clear();
        } else
            res.insert(now);
        
    }
    cout << endl << counter << endl;
}