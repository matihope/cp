#include <bits/stdc++.h>

using namespace std;

vector<int> phis;
vector<int> divs;
void sieve(int n){
    vector<bool> prime(n + 1, 1);
    for(long long i = 2; i <= n; i++){
        if(prime[i]){
            divs[i] = i;
            for(long long j = i * i; j <= n; j += i){
                if(prime[j]){
                    prime[j] = false;
                    divs[j] = i;
                }
            }
        }
    }
}

int phi(int n){
    int ans = 1;
    int count = 0;
    int divisor = divs[n];
    while(n > 1){
        n /= divs[n];
        count++;
        if(divisor != divs[n]){
            ans *= divisor - 1;
            count = 0;
            divisor = divs[n];
        } else {
            ans *= divisor;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    if(n < m) swap(n, m);
    divs.assign(m + 1, {});
    sieve(m);
    long long ans = 0;
    for(int i = 1; i <= m; ++i){
        long long a = (n / i);
        long long b = (m / i);
        long long p = phi(i);
        ans += p * a * b;
    }
    cout << ans                                                                                                                                                 q << endl;
}