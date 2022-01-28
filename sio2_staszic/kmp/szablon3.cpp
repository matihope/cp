#include <bits/stdc++.h>

using namespace std;

vector<int> ps;

void gen_ps(const string& s){
    ps[0] = -1;
    ps[1] = 0; 
    int l = 0;
    for(int i = 2; i < s.size(); ++i){
        l = ps[i - 1];
        if(ps[ps[i - 1]] < l && ps[ps[i - 1]] > 0)
            l = ps[ps[i - 1]];
        while(l >= 0 && s[l + 1] != s[i]){
            l = ps[l];
        }
        ps[i] = ++l;
    }
        
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    s = '$' + s;
    ps.assign(s.size(), 0);
    gen_ps(s);
    for(auto c: ps)
        cout << c << " ";
}