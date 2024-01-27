#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

constexpr LL MOD = 1e9;

LL mod(LL n) { return ((n % MOD) + MOD) % MOD; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, i;
	cin >> n;
	vector<LL> dp(10001, 0);
	LL         sum = 0;
	while (n--) {
		cin >> i;

		LL diff = mod(sum - dp[i]);
		dp[i]   = sum + 1;
		sum     = mod(dp[i] + diff);
	}

	cout << sum << '\n';
}
