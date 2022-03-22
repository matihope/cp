#include <bits/stdc++.h>

using namespace std;

long long pow(long long a, int power, int mod){
    long long ans = 1;
    for(int i = 0; i < 32; ++i){
        if(power & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        power /= 2;
    }
    return ans % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, c, p;
    while(cin >> a >> c >> p){
        int k = ceil(sqrt(p));
        int ak = pow(a, k, p), inv_a = pow(a, p - 2, p);

        // find all y_values
        vector<pair<int, int>> ys;
        for(int i = k; i >= 0; --i){
            int v = c * pow(inv_a, i, p) % p;
            ys.push_back({v, i});
        }
        sort(ys.begin(), ys.end(), less<pair<int, int>>());

        int b = -1;
        for(int i = 0; i <= k; ++i){
            int v = pow(ak, i, p);
            auto it = lower_bound(ys.begin(), ys.end(), pair<int, int>(v, 0));
            if(it->first == v){
                b = i * k + it->second;
                break;
            }
        }
        cout << b << endl;
    }
}
