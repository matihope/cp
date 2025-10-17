/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include "../leet.hpp"
#include <unordered_map>

// @lc code=start
class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0;
    int r = height.size() - 1;
    int max_size = 0;
    while (l < r) {
      max_size = max(max_size, min(height[l], height[r]) * (r - l));
      if(height[l] < height[r]) l++;
      else r--;
    }
    return max_size;
  }
};
// @lc code=end

auto &&run = [](vector<int> &x) { return Solution().maxArea(x); };

TEST(simple) {
  vector<int> x = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  ASSERT_EQUAL(49, run(x));
}

TEST(0) {
  vector<int> x = {1, 8, 6, 2};
  ASSERT_EQUAL(6, run(x));
}
