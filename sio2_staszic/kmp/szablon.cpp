#include <bits/stdc++.h>

using namespace std;

void fill_ps(const string& s, vector<int>& t){
    t[0] = -1;
    t[1] = 0;
    int l = 0;
    for(size_t i = 2; i < s.size(); ++i){
        l = t[i - 1];
        while(l >= 0 && s[l + 1] != s[i]) l = t[l];
        t[i] = ++l;
    }
}

bool check_fit(string s, int m, vector<int>& t){
    string key = s.substr(1, m);
    s = '$' + key + '$' + s;
    t[0] = -1;
    t[1] = 0;
    int l = 0;
    for(size_t i = 2; i < s.size(); ++i){
        l = t[i - 1];
        while(l >= 0 && s[l + 1] != s[i]) l = t[l];
        t[i] = ++l;
    }
    // cout << m << endl;
    // for(int i = 0; i < s.size(); ++i) cout << s[i] << " ";
    // cout << '\n';
    // for(int i = 0; i < s.size(); ++i) cout << t[i] << " ";
    // cout << '\n';
    int last_appeared = m + 1;
    if(t[s.size() - 1] != m) return false;
    for(int i = m + 2; i < s.size(); ++i){
        if(t[i] == m) last_appeared = i;
        if(i - last_appeared > m) return false;
    }
    
    return true;
}

int main(){
    #ifndef LOCAL_H
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #endif

    string s;
    cin >> s;
    // s = '$' + s;
    if(s.size() == 1){
        cout << 1 << endl;
        return 0;
    }
    int l = 1, r = int(s.size()), m;
    vector<int> prefsuf(2 * s.size() + 2, 0);
    fill_ps(s, prefsuf);
    cout << "New string len: " << prefsuf[s.size() - 1] << endl;
}