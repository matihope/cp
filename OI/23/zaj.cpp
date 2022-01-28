#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> s1(n), s2(m);
    for(auto& i: s1) cin >> i;
    for(auto& i: s2) cin >> i;

    // string s1, s2;
    // cin >> s1 >> s2;
    // int n = s1.size(), m = s2.size();

    vector<long long> v(m + 1, 0);
    long long ukos1, ukos2;
    stack<int> ans;
    for(int i = 0; i < n; ++i){
        ukos1 = v[0];
        for(int j = 1; j <= m; ++j){
            ukos2 = v[j];
            if(s1[i] == s2[j - 1]){
                v[j] = ukos1 + 1;
            }
            else 
                v[j] = max(v[j - 1], v[j]);
            ukos1 = ukos2;
        }
    }
    // int v_pos = m;
    // int s_pos = n - 1;
    // while(v_pos > 0 && s_pos >= 0){
    //     bool greater = v[v_pos - 1] < v[v_pos];
    //     bool same = s1[s_pos] == s2[v_pos - 1];
    //     if(same && greater){
    //         ans.push(s2[v_pos - 1]);
    //         s_pos--;
    //         v_pos--;
    //     } else if(same && !greater) {
    //         v_pos--;
    //     } else if(!same && greater) {
    //         s_pos--;
    //     }
    // }
    int b = ans.top(); ans.pop();
    int counter = 0;
    while(!ans.empty()){
        int now = ans.top();
        ans.pop();
        if(now == b){
            counter += 2;
            if(!ans.empty()){
                b = ans.top();
                ans.pop();
            }
        }
        else
            b = now;
    }
    cout << counter << endl;
}