#include <bits/stdc++.h> 

using namespace std;

vector<int> lcp;

void kmp(const string& s, vector<int>& ps){
    ps[0] = -1;
    int l = 0;
    for(int i = 1; i < s.length(); i++){
        l = ps[i - 1];
        while(l >= 0 && s[l + 1] != s[i])
            l = ps[l];
        ps[i] = ++l;
    }
}

vector<int> find_smallest_ps;
string sm;
int find_sm(){
    find_smallest_ps.assign(sm.size(), 0);
    kmp(sm, find_smallest_ps);
    if(sm.size() > 2){
        sm = '$' + sm.substr(1, find_smallest_ps.back());
    }
    return find_smallest_ps.back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s1;
    cin >> s1;
    int curr_best = s1.size();

    sm = '$' + s1;
    int to_test = 2;
    stack<int> pfs;
    while(pfs.size() == 0 || find_smallest_ps.back() != 1){
        pfs.push(find_sm());
    }

    while(!pfs.empty()){
        int s = pfs.top(); pfs.pop();
        if(pfs.empty() || s * 2 > pfs.top()){
            vector<int> prefsuf(s + s1.size() + 2, 0);
            string s_now = '$' + s1.substr(0, s) + '$' + s1;
            kmp(s_now, prefsuf);
            bool good = true;
            for(int i = s + 2; i < s_now.size(); ++i){
                if(prefsuf[i] == 0){
                    good = false;
                    break;
                }
            }
            if(good){
                cout << s << endl;
                return 0;
            }
        }
    }
    cout << s1.size() << endl;
}