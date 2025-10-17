/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include "../leet.hpp"

// @lc code=start

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    unordered_map<int, int> acc;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
      acc[nums[i]]++;
    set<array<int, 3>> sol;
    for (size_t i = 0; i < nums.size() - 1; i++) {
      acc[nums[i]]--;
      for (size_t j = i + 1; j < nums.size(); j++) {
        acc[nums[j]]--;
        int val = -(nums[i] + nums[j]);
        if (acc.contains(val) && acc[val] > 0) {
          array<int, 3> curr = {nums[i], nums[j], val};
          if (curr[0] > curr[1])
            swap(curr[0], curr[1]);
          if (curr[0] > curr[2])
            swap(curr[0], curr[2]);
          if (curr[1] > curr[2])
            swap(curr[1], curr[2]);
          sol.insert(curr);
        }
        acc[nums[j]]++;
      }
      acc[nums[i]]++;
    }
    vector<vector<int>> res;
    for (auto a : sol) {
      res.emplace_back(a.begin(), a.end());
    }
    return res;
  }
};
// @lc code=end

TEST(2) {
  vector<int> ints = {0, 0, 1};
  vector<vector<int>> res{};
  vector<vector<int>> got = Solution().threeSum(ints);
  ASSERT_EQUAL(res.size(), got.size());
}
TEST(3) {
  vector<int> ints = {0, 1, 1};
  vector<vector<int>> res{};
  vector<vector<int>> got = Solution().threeSum(ints);
  ASSERT_EQUAL(res.size(), got.size());
}

TEST(1) {
  vector<int> ints = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res{{-1, -1, 2}, {-1, 0, 1}};
  vector<vector<int>> got = Solution().threeSum(ints);
  ASSERT_EQUAL(res, got);
}
