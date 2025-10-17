/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
bool dp[1001][1001]{};
class Solution {
public:
  string longestPalindrome(string s) {
    for(int i = 0; i < s.size(); i++) {
        dp[0][i] = true;
        if(s.size() > 1)
            dp[1][i] = true;
    }

    int max_len = 1;
    int max_pos = 0;

    for (int len = 2; len <= s.size(); len++) {
      for (int j = len - 1; j < s.size(); j++) {
        if ((dp[len][j] = dp[len - 2][j - 1] && s[j - (len - 2) - 1] == s[j])) {
          max_len = len;
          max_pos = j;
        }
      }
    }
    return s.substr(max_pos - max_len + 1, max_len);
  }
};
// @lc code=end

int main() { cout << Solution().longestPalindrome("a"); }
