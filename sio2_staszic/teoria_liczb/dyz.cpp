#include <bits/stdc++.h>

using namespace std;

vector<int> pref(1'000'001, 0);
void seive(){
    vector<bool> prime(1'000'001, 1);
    int primes = 0;
    for(long long i = 2; i <= 1'000'000; ++i){
        pref[i] = primes;
        if(prime[i]){
            pref[i] = ++primes;
            for(long long j = i * i; j <= 1'000'000; j += i)
                prime[j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n, a, b;
    cin >> n;
    seive();

    while(n--){
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << endl;
    }
}