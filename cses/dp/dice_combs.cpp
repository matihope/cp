#include <iostream>
#include <vector>
#include <array>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef array<array<long long, 6>, 6> MTRX;
constexpr int MOD = 1e9 + 7;

MTRX mul(MTRX a, MTRX b) {
    MTRX ans;
    for(int i = 0; i < 6; ++i){
        ans[i].fill(0);
        for(int j = 0; j < 6; ++j)
            for(int k = 0; k < 6; ++k)
                ans[i][k] = (ans[i][k] + (a[i][j] * b[j][k] % MOD)) % MOD;
    }

    return ans;
}

int quick_pow(MTRX a, int p){
    MTRX ans;
    for(int i = 0; i < 6; ++i){
        ans[i].fill(0);
        ans[i][i] = 1;
    }
    while(p){
        if(p&1)
            ans = mul(a, ans);
        a = mul(a, a);
        p /= 2;
    }
    return ans[5][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    MTRX def;
    for(int i = 0; i < 6; ++i){
        def[i].fill(0);
        def[i][0] = 1;
        if(i + 1 < 6)
            def[i][i + 1] = 1;
    }
    cout << quick_pow(def, n + 1) << endl;
}