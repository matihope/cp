#include <bits/stdc++.h>

using namespace std;

#define INF_I 1000000001
#define INF_LL 1000000000000000001
typedef long long LL;
typedef vector<int> VI;

void kmp(const string s, vector<int>& ps){
    ps.assign(s.size(), 0);
    ps[0] = -1;
    int l = 0;
    for(int i = 2; i < s.size(); i++){
        l = ps[i - 1];
        while(l >= 0 && s[i] != s[l + 1])
            l = ps[l];
        ps[i] = ++l;
    }
}

constexpr int m = 1e9 + 7, p = 401;
vector<int> hashes, pots;
void gen_hashes(const string s){
    hashes.assign(s.size() + 1, 0);
    pots.assign(s.size() + 1, 0);
    pots[0] = 1;
    for(int i = 1; i <= s.size(); ++i){
        hashes[i] = (((LL)hashes[i - 1] * p % m) + s[i - 1]) % m;
        pots[i] = (LL)pots[i - 1] * p % m;
    }
}

int gen_key_hash(const string s){
    int ans = 0;
    for(int i = 0; i < s.size(); ++i)
        ans = (((LL)ans * p % m) + s[i]) % m;
    return ans;
}

int get_hash(int l, int r){
    int ans = LL(hashes[r]) - LL(hashes[l]) * pots[r - l] % m;
    if(ans < 0)
        return ans + m;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int z;
    cin >> z;
    while(z--){
        vector<int> ps;
        string s, key;
        cin >> s >> key;
        while(s.size()){
            int counter = 0;
            int min_pos = 0;
            if(key.size() <= s.size()){
                kmp('$' + key + '$' + s, ps);
                int min_ps = INF_I;
                int counts = 0;
                int key_hash = gen_key_hash(key);
                gen_hashes(s);
                for(int i = 0; i < s.size() - 1; ++i){
                    if(i + key.size() - 1 < s.size()){
                        if(get_hash(i, i + key.size()) == key_hash){
                            counter++;
                        }
                    }
                    if(ps[i + key.size() + 2] < min_ps && ps[i + key.size() + 1] != key.size() && ps[i + key.size() + 1] >= ps[i + key.size() + 2]){
                        min_ps = ps[i + key.size() + 2];
                        min_pos = i;
                    }
                }
            }
            cout << counter << " ";
            s.erase(s.begin() + min_pos);
        }
        cout << 0 << endl;
    }
}