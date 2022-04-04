#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

typedef vector<long long> VLL;
typedef vector<VLL> MTRX;

MTRX multiply_matrices(MTRX& transformer, MTRX& operatee) {
    MTRX ans(operatee.size(), VLL(operatee[0].size(), 0));

    for(int i = 0; i < operatee.size(); ++i)
        for(int j = 0; j < operatee[0].size(); ++j)
            for(int k = 0; k < ans[0].size(); ++k)
                ans[i][k] = ((operatee[i][j] * transformer[j][k] % MOD) + ans[i][k]) % MOD;

    return ans;
}

MTRX quick_matrix_power(MTRX matrix, unsigned long long power){
    MTRX ans = matrix;
    while(power){
        if(power & 1) ans = multiply_matrices(ans, matrix);
        matrix = multiply_matrices(matrix, matrix);
        power /= 2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while(q--){
        long long n;
        int k;
        cin >> n >> k;

        MTRX matrix;
        matrix.assign(k, VLL(k, 0));
        for(int i = 0; i < k; ++i) matrix[i][0] = 1;
        for(int i = 1; i < k; ++i) matrix[i - 1][i] = 1;

        cout << quick_matrix_power(matrix, n)[k - 1][0] << endl;
    }
}