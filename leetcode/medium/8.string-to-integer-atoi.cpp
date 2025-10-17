/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
  int myAtoi(string s) {
    bool neg = false;
    int value = 0;
    int pos = 0;

    while (pos < s.size() && s[pos] == ' ')
      pos++;

    if (pos < s.size() && (s[pos] == '+' || s[pos] == '-')) {
      neg = s[pos] == '-';
      pos++;
    }

    int max_good = 2147483647;
    int min_good = -2147483648;
    while (pos < s.size() && '0' <= s[pos] && s[pos] <= '9') {
      if (value > max_good / 10) {
        if (neg)
          return min_good;
        return max_good;
      }
      value *= 10;

      int curr = s[pos] - '0';
      if (!neg && max_good - curr < value)
        return max_good;
      if (neg && min_good + curr > -value)
        return min_good;
      if (neg && value == max_good - 7 && curr == 8)
        return min_good;
      value += curr;

      pos++;
    }

    return neg ? -value : value;
  }
};
// @lc code=end
