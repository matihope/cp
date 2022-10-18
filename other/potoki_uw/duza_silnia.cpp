#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

constexpr int MOD = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    LL n;
    cin >> n;
    LL counter = 1;
    if(n >= 45)
    {
        cout << 0 << endl;
        return 0;
    }
    for(LL j = 1; j <= n; ++j){
        counter *= j;
        counter %= MOD;
    }
    cout << counter % MOD << endl;
}
