#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6+1;
const int p = 401;
constexpr int m[] = {int(1e9 + 7), int(1e9 + 9)};
const int S = 2;

int tab[N * 2][2], pot[N * 2][2];

void gen_hashes(string& s){
    pot[0][0] = 1;
    pot[0][1] = 1;
    for(int i = 1; i <= s.size(); ++i){
        for(int j = 0; j < S; ++j){
            tab[i][j] = ((LL(tab[i - 1][j]) * p % m[j]) + s[i - 1]) % m[j];
            pot[i][j] = LL(pot[i - 1][j]) * p % m[j];
        }
    }
}

PII get_hashes(int l, int r){
    int h1 = ((LL)tab[r][0] - (LL)tab[l][0] * pot[r - l][0]) % m[0];
    if(h1 < 0) h1 += m[0];
    int h2 = ((LL)tab[r][1] - (LL)tab[l][1] * pot[r - l][1]) % m[1];
    if(h2 < 0) h2 += m[1];
    return {h1, h2};
}

bool cmp_hashes(PII h1, PII h2){
    return h1.first == h2.first && h1.second == h2.second;
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
                    if(cmp_hashes(get_hashes(pos, pos + m), get_hashes(i, i + m)))
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