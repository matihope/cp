#include <bits/stdc++.h>

using namespace std;

void kmp(const string& s, vector<int>& ps){
    ps.assign(s.size(), 0);
    ps[0] = -1;
    int l = 0;
    for(int i = 2; i < s.size(); i++){
        l = ps[i - 1];
        while(l >= 0 && s[l + 1] != s[i])
            l = ps[l];
        ps[i] = ++l;
    }
}

typedef long long LL;
vector<int> hashes, pot;
constexpr int m = 1e9 + 7, p = 397;
void gen_hashes(const string& s){
    hashes.assign(s.size() + 1, 0);
    pot.assign(s.size() + 1, 0);
    pot[0] = 1;
    for(int i = 1; i <= s.size(); i++){
        hashes[i] = (LL(hashes[i - 1]) * p % m + s[i - 1]) % m;
        pot[i] = LL(pot[i - 1]) * p % m;
    }
}

int get_hash(int l, int r){
    int ans = LL(hashes[r]) - LL(hashes[l]) * pot[r - l] % m;
    if(ans < 0)
        return ans + m;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    gen_hashes(s);
    vector<int> ps;
    size_t min_size = s.length();
    for(size_t i = 1; i < s.length(); ++i){

        if(get_hash(0, i) != get_hash(s.size() - i, s.size()))
            continue;

        string n = '$' + s.substr(0, i) + '$' + s;
        kmp(n, ps);
        bool good = true;
        for(int j = i + 2; j < n.size(); ++j){
            if(ps[j] == 0){
                good = false;
                break;
            }
        }
        if(ps[n.size() - 1] == i && good){
            min_size = min(min_size, i);
            break;
        } else {
            i = i * 2 - 1;
        }
    }
    cout << min_size << endl;
}