/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include "../leet.hpp"
#include <cmath>

// @lc code=start
class Solution {
public:
  int find(vector<int> &nums, int value, int l, int r) {
    while (r - l) {
      int mid = (l + r) / 2;
      if (nums[mid] < value)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }

  int threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int mid = 1;
    int smallest_diff = 100000000;
    int value = 0;
    for (int l = 0; l < nums.size() - 2; l++) {
      //   for (int r = mid + 1; r < nums.size(); r++) {
      // 9 26 42
      for (int r = l + 2; r < nums.size(); r++) {
        int sum = nums[l] + nums[r];
        int mid0 = find(nums, target - sum, l + 1, r - 1);
        int mid1 = find(nums, nums[mid0] + 1, l + 1, r - 1);
        int mid2 = find(nums, nums[mid0 - 1], l + 1, r - 1);
        for (auto mid : {mid0, mid1, mid2}) {
          if (auto diff = abs(sum + nums[mid] - target); diff < smallest_diff) {
            smallest_diff = diff;
            value = sum + nums[mid];
          }
        }
      }
    }

    return value;
  }
};
// @lc code=end

TEST(0) {
  vector<int> nums = {-1, 2, 1, -4};
  ASSERT_EQUAL(2, Solution().threeSumClosest(nums, 1));
}

TEST(1) {
  vector<int> nums = {-84, 92, 26, 19, -7, 9, 42, -51, 8, 30, -100, -13, -38};
  ASSERT_EQUAL(77, Solution().threeSumClosest(nums, 78));
}
