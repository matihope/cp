#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;

u64 putQueenAt(u64 board, u64 new_queen_x, u64 new_queen_y) {
  u64 diff = new_queen_x + 8 - new_queen_y; // in [-8, 8]
  u64 sum = new_queen_x + new_queen_y;      // in [0, 16]
  // (48-x-40](40-y-32](32-sum-16](16-diff-0]
  board |= ((1ULL << diff));              // put diff
  board |= ((1ULL << sum) << 16);         // put sum
  board |= ((1ULL << new_queen_x) << 32); // put x
  board |= ((1ULL << new_queen_y) << 40); // put y
  return board;
}

bool canPutQueenAt(u64 board, u64 new_queen_x, u64 new_queen_y) {
  u64 diff_now = 1ULL << (new_queen_x + 8 - new_queen_y);
  u64 diffs = (board & 0xFFFF);
  if (diffs & diff_now)
    return false;
  u64 sum_now = 1ULL << (new_queen_x + new_queen_y);
  u64 sums = ((board >> 16) & 0xFFFF);
  if (sums & sum_now)
    return false;
  if (((board >> 32) & 0xFF) & (1ULL << new_queen_x))
    return false;
  if (((board >> 40) & 0xFF) & (1ULL << new_queen_y))
    return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  std::array<std::array<char, 8>, 8> input;

  for (u64 i = 0; i < 8; i++) {
    for (u64 j = 0; j < 8; j++) {
      std::cin >> input[i][j];
    }
  }

  std::vector<u64> order = {0, 1, 2, 3, 4, 5, 6, 7};
  u64 counter = 0;
  do {
    auto board = 0;
    bool good = true;
    for (auto row = 0; row < 8; row++) {
      auto col = order[row];
      if (input[row][col] == '*') {
        good = false;
        break;
      }
      if (canPutQueenAt(board, row, col)) {
        board = putQueenAt(board, row, col);
      } else {
        good = false;
        break;
      }
    }
    if (good)
      counter++;
  } while (std::next_permutation(order.begin(), order.end()));
  std::cout << counter << '\n';
}
