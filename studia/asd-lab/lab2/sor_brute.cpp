#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

VI performSort(const VI &vec) {
  deque<int> q;
  q.push_back(vec[0]);
  for (int i = 1; i < vec.size(); i++) {
    if (vec[i - 1] > vec[i])
      q.push_front(vec[i]);
    else
      q.push_back(vec[i]);
  }
  VI vec3;
  while (!q.empty()) {
    vec3.push_back(q.front());
    q.pop_front();
  }
  return vec3;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  VI vecOriginal(n);
  for (auto &i : vecOriginal) cin >> i;

//   for (auto i : performSort(vecOriginal)) cout << i << ' ';
//   cout << '\n';

  VI vecPerm = vecOriginal;
  std::sort(vecPerm.begin(), vecPerm.end());
  int counter = 0;
  do {
    VI vecSorted = performSort(vecPerm);
    if (vecSorted == vecOriginal) {
      counter++;
      for (auto elem : vecPerm) cout << elem << ' ';
      cout << '\n';
    }
  } while (next_permutation(vecPerm.begin(), vecPerm.end()));
  std::cout << counter << endl;
}
