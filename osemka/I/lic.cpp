#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
constexpr int MAX_N = 1e6 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> is_prime(MAX_N, 1);
    is_prime[1] = false;
    for(LL i = 2; i < MAX_N; ++i){
        if(is_prime[i]){
            for(LL j = i * i; j < MAX_N; j += i)
                is_prime[j] = false;
        }
    }

    // vector<int> prefsum(MAX_N, 0);
    // for(int i = 2; i < MAX_N; ++i)
    //     prefsum[i] = prefsum[i - 1] + is_prime[i];

    int n, x, y;
    cin >> n;
    while(n--){
        cin >> x >> y;
        cout << is_prime[x] << endl;
    }
}
