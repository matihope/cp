#include <iostream>
#include <vector>

using namespace std;

typedef long long   LL;
typedef vector<int> VI;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int prev;
	int price = 0;
	long long gain  = 0;
	cin >> prev;
	for (int i = 1; i < n; i++) {
		cin >> price;
		if (price > prev) gain += price - prev;
		prev = price;
	}
	cout << gain << '\n';
}
