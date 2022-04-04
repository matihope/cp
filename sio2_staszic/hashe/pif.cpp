#include <bits/stdc++.h> 

using namespace std;

typedef long long LL;

const int S = 2;
typedef array<int, S> HASH;
const int N = 1e6 + 1;
const int M[] = {int(1e9) + 7, int(1e9) + 9};
const int p = 401;
int tab[N][S], pot[N][S];
string s;

void gen_hashes(const string& s){
    for(int i = 0; i < S; ++i)
        pot[0][i] = 1;
    
    for(int i = 1; i <= s.size(); ++i){
        for(int j = 0; j < S; ++j){
            tab[i][j] = ((LL)tab[i - 1][j] * p + s[i - 1]) % M[j];
            pot[i][j] = (LL)pot[i - 1][j] * p % M[j];
        }
    }
}

HASH get_hashes(int l, int r){
    HASH a;
    for(int i = 0; i < S; ++i){
        if(r - l != 1){
            a[i] = (tab[r][i] - (LL)tab[l][i] * pot[r - l][i]) % M[i];
            if(a[i] < 0){
                a[i] += M[i];
            }
        } else {
            a[i] = s[r - 1];
        }
    }
    return a;
}

bool cmp_hashes(const HASH& a, const HASH& b) {
    for(size_t i = 0; i < S; ++i)
        if(a[i] != b[i])
            return false;
    return true;
}

string dec2bin(int n){
    string ans;
    while(n > 0){
        ans = to_string(n % 2) + ans;
        n /= 2;
    }
    return ans;
}

bool try_to_fit(int n, int l){
    HASH w0 = get_hashes(0, l), w1 = get_hashes(l, l * 2);
    int pos = 2 * l;
    for(int i = 2; i < n; ++i) {
        for(auto& c: dec2bin(i)){
            if(pos + l > n){
                if(c == '0'){
                    if(!cmp_hashes(get_hashes(0, n - pos), get_hashes(pos, n)))
                        return false;
                }
                else if (c == '1'){
                    if(!cmp_hashes(get_hashes(l, l + n - pos), get_hashes(pos, n)))
                        return false;
                }
                return true;
            }
            if(c == '1'){
                if(!cmp_hashes(w1, get_hashes(pos, pos + l)))
                    return false;
            }
            else if(c == '0'){
                if(!cmp_hashes(w0, get_hashes(pos, pos + l)))
                    return false;
            }
            pos += l;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin >> s;
    if(n == 1){ cout << 1 << endl; return 0; }
    if(n == 2){ cout << 2 << endl; return 0; }
    string s2 = s;
    sort(s2.begin(), s2.end());
    if(s2.back() == s2.front()) { cout << n << endl; return 0; }
    gen_hashes(s);
    int l = 1;
    int pos = 3;
    bool found = false;
    while(pos < n){
        if(s[0] == s[pos]){
            HASH h1 = get_hashes(l, l * 2);
            HASH h2 = get_hashes(l * 2, l * 3);
            while(cmp_hashes(h1, h2)){
                l++;
                h1 = get_hashes(l, l * 2);
                h2 = get_hashes(l * 2, l * 3);
                if(!cmp_hashes(h1, h2)){ 
                    l--;
                    h1 = get_hashes(l, l * 2);
                    h2 = get_hashes(l * 2, l * 3);
                    break;
                }
            }
            if(cmp_hashes(h1, h2) && try_to_fit(n, l))
                found = true;
            
        }
        if(found) break;
        l++;
        pos = l * 3;
    }
    if(found)
        cout << int(ceil(double(n) / l)) << endl; 
    else{
        for(int l2 = 1; l2 * 3 < n; ++l2){
            if(cmp_hashes(get_hashes(n - l2, n), get_hashes((n - l2) / 2, (n - l2) / 2 + l2)) && (n - l2) % 2 == 0){
                cout << 3 << endl;
                return 0;
            }
        }
        cout << 2 << endl;
    }
}