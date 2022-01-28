#include <bits/stdc++.h> 

using namespace std;

typedef long long LL;

const LL p = 401;
const LL M1 = 1e9 + 7;
const LL M2 = 1e9 + 9;

vector<LL> pot1, pot2, hashe1, hashe2;

int get_hash(int l, int r, vector<LL>& ha, vector<LL>& po, LL M){
    LL v = (ha[r] - ha[l] * po[r - l]) % M;
    if(v < 0) return v + M;
    return v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s, key;
    cin >> s;
    int k, n;
    cin >> k;
    pot1.assign(s.size() + 1, 0);
    pot2.assign(s.size() + 1, 0);
    hashe1.assign(s.size() + 1, 0);
    hashe2.assign(s.size() + 1, 0);
    pot1[0] = 1;
    pot2[0] = 1;
    for(size_t i = 1; i <= s.size(); ++i){
        hashe1[i] = ((hashe1[i - 1] * p % M1) + s[i - 1]) % M1;
        hashe2[i] = ((hashe2[i - 1] * p % M2) + s[i - 1]) % M2;
        pot1[i] = (pot1[i - 1] * p) % M1;
        pot2[i] = (pot2[i - 1] * p) % M2;
    }
    while(k--){
        cin >> n;
        int size = 0;
        vector<tuple<LL, LL, bool, bool, int>> thing;
        for(int i = 0; i < n; ++i){
            LL h1 = 0, h2 = 0;
            cin >> key;
            size = key.size();
            for(auto& c: key){
                h1 = ((h1 * p % M1) + c) % M1;
                h2 = ((h2 * p % M2) + c) % M2;
            }
            thing.push_back({h1, h2, false, false, i});
        }
        vector<int> hashes1, hashes2;
        for(int i = size; i <= s.size(); ++i){
            hashes1.push_back(get_hash(i - size, i, hashe1, pot1, M1));
            hashes2.push_back(get_hash(i - size, i, hashe2, pot2, M2));
        }
        sort(hashes1.begin(), hashes1.end());
        sort(hashes2.begin(), hashes2.end());
        sort(thing.begin(), thing.end());
        int l = 0, r = 0;
        while(l < hashes1.size() && r < thing.size()) {
            int v = get<0>(thing[r]);
            if(hashes1[l] == v) get<2>(thing[r++]) = true;
            else if(hashes1[l] > v) r++;
            else l++;
        }
        auto cmp1 = [&](const tuple<LL, LL, bool, bool, int> a, const tuple<LL, LL, bool, bool, int> b){ return get<1>(a) < get<1>(b); };
        sort(thing.begin(), thing.end(), cmp1);
        l = 0, r = 0;
        while(l < hashes2.size() && r < thing.size()) {
            int v = get<1>(thing[r]);
            if(hashes2[l] == v) get<3>(thing[r++]) = true;
            else if(hashes2[l] > v) r++;
            else l++;
        }
        auto cmp2 = [&](const tuple<LL, LL, bool, bool, int> a, const tuple<LL, LL, bool, bool, int> b){ return get<4>(a) < get<4>(b); };
        sort(thing.begin(), thing.end(), cmp2);
        for(auto& h : thing) {
            cout << ((get<2>(h) && get<3>(h)) ? "OK" : "NIE") << endl;
        }
    }
    return 0;
}