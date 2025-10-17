#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

using i64 = std::int64_t;
using i32 = std::int32_t;
using u64 = std::uint64_t;
using u32 = std::uint32_t;

// Moves a tower of size n from `from` to `to` using an `additional` as a helper
void hanoi(i32 n, i32 from, i32 to, i32 additional) {
    if(n == 0) return;
    hanoi(n - 1, from, additional, to);
    std::cout << from << " " << to << '\n';
    hanoi(n - 1, additional, to, from);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i32 n;
  cin >> n;
  std::cout << std::pow(2, n) - 1 << '\n';
  hanoi(n, 1, 3, 2);
}
