#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

typedef vector<long long> VLL;
typedef vector<VLL> MTRX;

MTRX multiply_matrices(MTRX& transformer, MTRX& operatee) {
    MTRX ans(operatee.size(), VLL(operatee[0].size(), 0));

    for(int i = 0; i < operatee.size(); ++i)
        for(int j = 0; j < operatee[0].size(); ++j)
            for(int l = 0; l < ans[0].size(); ++l)
                ans[i][l] = ((operatee[i][j] * transformer[j][l] % MOD) + ans[i][l]) % MOD;

    return ans;
}

MTRX quick_matrix_power(MTRX matrix, unsigned long long power){
    MTRX ans = matrix;
    power--;
    for(int i = 0; i < 64; i++){
        if(power & 1)
            ans = multiply_matrices(ans, matrix);
        matrix = multiply_matrices(matrix, matrix);
        power /= 2;
    }
    return ans;
}

long long fib(long long n){
    return quick_matrix_power({ {1, 1}, {1, 0} }, n)[1][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;
    // F[0] + F[1] + F[2] + F[3] + F[4] + F[5] ... + F[n] = F[n] * F[n + 1]
    long long ans = (fib(b + 1) * fib(b + 2) % MOD - fib(a) * fib(a + 1) % MOD + MOD) % MOD;
    cout << ans << endl;
}