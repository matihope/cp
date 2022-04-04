#include <bits/stdc++.h>

using namespace std;

void kmp(const string& s, vector<int>& ps){
    ps.assign(s.size(), 0);
    ps[0] = -1;
    int l = 0;
    for(int i = 2; i < s.size(); i++){
        l = ps[i - 1];
        while(l >= 0 && s[l + 1] != s[i]) l = ps[l];
        ps[i] = ++l;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<int> ps;
    int min_size = s.length();
    kmp('$' + s, ps);
    int curr_size = ps.back();

    stack<int> sizes;
    while(curr_size != 0){
        sizes.push(curr_size);
        curr_size = ps[curr_size];
    }
    
    int mini = 0;
    while(!sizes.empty()){
        int now_size = sizes.top(); sizes.pop();
        if(now_size < mini)
            continue;
        string n = '$' + s.substr(0, now_size) + '$' + s;
        kmp(n, ps);
        bool good = true;
        for(int j = now_size + 2; j < n.size(); ++j){
            if(ps[j] == 0){
                good = false;
                break;
            }
        }
        if(ps.back() == now_size && good){
            min_size = min(min_size, now_size);
            break;
        } else {
            mini = now_size * 2;
        }
    }
    cout << min_size << endl;
}