#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

void zfunc(const string& a, std::vector<int>& values) {
  int answer = 0;
  for (int b_start = 1; b_start < a.size(); b_start++) {
    for (int i = 0; i < b_start && i + b_start < a.size(); i++) {
      if (a[i] == a[b_start + i])
        values[b_start]++;
      else
        break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s1, s2;
  cin >> s1 >> s2;

  // normal
  string connected = s1 + '$' + s2;
  vector<int> z_values_normal(connected.size(), 0);
  zfunc(connected, z_values_normal);

  // reversed
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  connected = s1 + '$' + s2;
  vector<int> z_values_inverted(connected.size(), 0);
  zfunc(connected, z_values_inverted);

  // find solution
  int best = 0;
  int s1_s = s1.size();
  for (size_t i = s1.size() + 1, j = z_values_inverted.size() - s1.size();
       i <= connected.size() - s1.size(); i++, j--)
    best = max(best, min(s1_s, z_values_normal[i] + z_values_inverted[j]));
  cout << s1_s - best << endl;
}
