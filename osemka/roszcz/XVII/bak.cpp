#include <array>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

constexpr LL MOD = 1e9 + 7;

typedef vector<long long> VLL;
using MTRX = std::array<std::array<LL, 3>, 3>;

MTRX multiply_matrices(MTRX& transformer, MTRX& operatee) {
  MTRX ans{};

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      for (int l = 0; l < 3; ++l)
        ans[i][l] =
            ((operatee[i][j] * transformer[j][l] % (MOD - 1)) + ans[i][l]) %
            (MOD - 1);

  return ans;
}

MTRX quick_matrix_power(MTRX matrix, long long power) {
  MTRX ans = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  while (power) {
    if (power & 1) ans = multiply_matrices(ans, matrix);
    matrix = multiply_matrices(matrix, matrix);
    power /= 2;
  }
  return ans;
}

LL quickPow(LL a, LL pow) {
  LL res = 1;
  while (pow) {
    if (pow & 1) res = a * res % MOD;
    a = a * a % MOD;
    pow /= 2;
  }
  return res;
}

void print(MTRX mat) {
  for (int i = 0; i < mat.size(); ++i) {
    for (int j = 0; j < mat[0].size(); ++j) {
      cout << mat[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  LL n0, n1, n2, q, day;
  cin >> n0 >> n1 >> n2 >> q;

  while (q--) {
    cin >> day;
    MTRX mat = {1LL, 1LL, 1LL, 1LL, 0LL, 0LL, 0LL, 1LL, 0LL};
    auto res = quick_matrix_power(mat, day - 3);

    // print(res);

    LL powerN0 = res[0][0] % (MOD - 1);
    LL powerN1 = (res[0][1] + res[1][1] + res[2][1]) % (MOD - 1);
    LL powerN2 = (res[0][0] + res[1][0] + res[2][0]) % (MOD - 1);

    cout << ((quickPow(n0, powerN0) * quickPow(n1, powerN1) % MOD) *
             quickPow(n2, powerN2)) %
                MOD
         << '\n';
  }
}
