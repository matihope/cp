/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
  void build(int n, int opened, string prev, vector<string> &result) {
    if (prev.size() == n) {
      if (opened == 0)
        result.push_back(prev);
      return;
    }
    build(n, opened + 1, prev + '(', result);
    if (opened)
      build(n, opened - 1, prev + ')', result);
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;
    build(n * 2, 0, "", result);
    return result;
  }
};
// @lc code=end
