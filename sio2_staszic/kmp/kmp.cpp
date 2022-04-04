#include <bits/stdc++.h>

using namespace std;

void fill_prefsuf(const string& s, vector<int>& ps){
    ps[0] = -1;
    ps[1] = 0;
    int l = 0;
    for(size_t i = 2; i < s.length(); ++i){
        l = ps[i - 1];
        while(l >= 0 && s[i] != s[l + 1]) l = ps[l];
        ps[i] = ++l;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    string key, str;
    cin >> key >> str;
    string neu = "$" + key + "$" + str;
    vector<int> prefsuf(neu.size(), 0);
    fill_prefsuf(neu, prefsuf);
    for(size_t i = 0; i < prefsuf.size(); ++i) {
        if(prefsuf[i] == n){
            cout << i - n * 2 << endl;
        }
    }
    for(int i = 0; i < prefsuf.size(); ++i){
        cout << prefsuf[i] << endl;
    }
}