#include <iostream>
#include <array>

using namespace std;

constexpr int MOD = 123456789;

#define N 26
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;
    MTRX matrix;
    for(int i = 0; i < N; ++i)
        matrix[i].fill(1);
    char x, y;
    while(b--){
        cin >> x >> y;
        matrix[x - 'a'][y - 'a'] = false;
    }
    matrix = quick_pow(matrix, a - 1);
    long long ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            ans += matrix[i][j];
    }
    cout << ans % MOD << endl;
}