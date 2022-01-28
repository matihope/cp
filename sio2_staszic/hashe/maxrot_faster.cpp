#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6+1;
const int p = 401;
constexpr int m = 1e9 + 7;

int tab[N * 2], pot[N * 2];

void gen_hashes(string& s){
    pot[0] = 1;
    for(int i = 1; i <= s.size(); ++i){
        tab[i] = ((LL(tab[i - 1]) * p % m) + s[i - 1]) % m;
        pot[i] = LL(pot[i - 1]) * p % m;
    }
}

int get_hashes(int l, int r){
    int h = ((LL)tab[r] - (LL)tab[l] * pot[r - l]) % m;
    if(h < 0) h += m;
    return h;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> k;
    while(k--){
        cin >> n;
        string s, s2;
        cin >> s;
        s2 = s;
        s = s + s;
        gen_hashes(s);
        int pos = 0;
        for(int i = 1; i < n; ++i){
            int l = 0, r = n / 2, m;
            if(s[pos] == s[i]){
                while(l < r){
                    m = (l + r) / 2;
                    if(get_hashes(pos, pos + m) == get_hashes(i, i + m))
                        l = m + 1;
                    else
                        r = m;
                }
                l--;
            }
            if(s[i + l] > s[pos + l]){
                pos = i;
            }
        }
        cout << s2.substr(pos) + s2.substr(0, pos) << endl;
    }
}