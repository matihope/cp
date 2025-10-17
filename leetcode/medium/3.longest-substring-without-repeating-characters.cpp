/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int head = 0, tail = 0, max_len = 0;
    unordered_map<char, int> counts;
    while (head < s.size()) {
      bool bad = counts[s[head++]]++ == 1;
      while (bad) {
        --counts[s[tail]];
        if (s[tail++] == s[head - 1])
          break;
      }
      max_len = max(max_len, head - tail);
    }
    return max_len;
  }
};
// @lc code=end
