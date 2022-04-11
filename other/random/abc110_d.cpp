#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

void find_divs(int n, vector<int>& divs){
    int i = 2, times = 0;
    while(1 < n){
        if(n % i != 0){
            if(times) 
                divs.push_back(times);
            times = 0;
            i++;
        } else {
            times++;
            n /= i;
        }
    }
    divs.push_back(times);
}

int quick_pow(long long a, int b){
    long long ans = 1;
    for(int i = 0; i < 32; ++i){
        if(b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

long long choose(int n, int k){
    long long ans = 1;
    long long divisor = 1;
    for(int i = n; i > max(n - k, k); --i)
        ans = ans * i % MOD;
    for(int i = 2; i <= min(n - k, k); ++i)
        divisor = divisor * i % MOD;
    return ans * quick_pow(divisor, MOD - 2) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> divs;
    find_divs(m, divs);
    long long ans = 1;
    for(auto& p : divs) ans = ans * choose(n + p - 1, n - 1) % MOD;
    
    cout << ans << endl;
}