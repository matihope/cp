/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
  int valAt(const int index, const vector<int> &nums1,
            const vector<int> &nums2) {

  }

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int l1 = 0, r1 = nums1.size() - 1, l2 = 0, r2 = nums2.size() - 1;
    int less_l1 = 0, less_l2 = 0, more_r1 = 0, more_r2 = 0;
    while (more + less < nums1.size() + nums2.size()) {
      int less = less_l1 + less_l2;
      int more = more_r1 + more_r2;
      int middle1 = (l1 + r1) / 2;
      int middle2 = (l2 + r2) / 2;
      if (less_l1 < more)
    }
  }
};
// @lc code=end
