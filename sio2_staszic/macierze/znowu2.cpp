#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 123456789;

vector<vector<long long>> matrix_multiplication(vector<vector<long long>>& a, vector<vector<long long>>& b){
    vector<vector<long long>> ans = { {0, 0}, {0, 0} };
    ans[0][0] = (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD;
    ans[0][1] = (a[0][1] * b[0][0] % MOD + a[1][1] * b[0][1] % MOD) % MOD;
    ans[1][0] = (a[0][0] * b[1][0] % MOD + a[1][0] * b[1][1] % MOD) % MOD;
    ans[1][1] = (a[0][1] * b[1][0] % MOD + a[1][1] * b[1][1] % MOD) % MOD;
    return ans;
}

vector<vector<long long>> quick_nth_fib(long long k){
    vector<vector<long long>> ans = { {1, 1}, {1, 0} };
    vector<vector<long long>> powering = ans;
    for(int i = 0; i < 64; i++){
        if(k & 1)
            ans = matrix_multiplication(ans, powering);
        powering = matrix_multiplication(powering, powering);
        k /= 2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    cout << quick_nth_fib(n)[1][1] << endl;
}