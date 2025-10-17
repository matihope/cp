/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
  int reverse(int x) {
    int value = 0;
    if (x == (1 << 31))
      return 0;
    int max_val = -((1 << 31) + 1);
    int copy_x = abs(x);
    while (copy_x) {
      if (max_val / 10 < value)
        return 0;
      value *= 10;
      if (max_val - (copy_x % 10) < value)
        return 0;
      value += copy_x % 10;
      copy_x /= 10;
    }
    if (x < 0)
      value *= -1;

    return value;
  }
};
// @lc code=end
