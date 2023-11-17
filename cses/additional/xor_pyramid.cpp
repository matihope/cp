#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  VI input(n);
  for (auto& i : input) cin >> i;

  while (input.size() > 1) {
    VI second;
    if (input.size() % 2 == 0) {
      for (int i = 0; i < input.size(); i += 2)
        second.push_back(input[i] ^ input[i + 1]);

    } else {
      for (int i = 1; i < input.size(); i++) {
        second.push_back(input[i - 1] ^ input[i]);
      }
    }
    input = std::move(second);
  }
  cout << input[0] << endl;
}
