#include <iostream>
#include <array>

using namespace std;

constexpr int MOD = 1e9;

#define N 3
typedef array<array<long long, N>, N> MTRX;

MTRX mul(MTRX& a, MTRX& b){
    MTRX ans;
    for(int i = 0; i < N; ++i){
        ans[i].fill(0);
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                ans[i][k] = (a[j][k] * b[i][j] % MOD + ans[i][k]) % MOD;
    }

    return ans;
}

MTRX quick_pow(MTRX matrix, long long power){
    MTRX ans;
    for(int i = 0; i < N; ++i){
        ans[i].fill(0);
        ans[i][i] = 1;
    }
    while(power){
        if(power & 1)
            ans = mul(matrix, ans);
        matrix = mul(matrix, matrix);
        power /= 2;
    }
    return ans;
}

long long LEO(int n){
    MTRX matrix = {{{1, 1, 0}, {1, 0, 0}, {1, 0, 1}}};
    MTRX ans = quick_pow(matrix, n);
    return ans[0][0] + ans[1][0] + ans[2][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a;
    cin >> a;
    for(int i = 0; i < a; i++){
        cout << LEO(i) << endl;
    }
}