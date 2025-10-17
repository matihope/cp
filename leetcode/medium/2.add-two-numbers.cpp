/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *root = new ListNode(0);
    ListNode *next = root;
    int carry = 0;
    while (l1 && l2) {
      int num = carry + l1->val + l2->val;
      carry = num / 10;
      next = next->next = new ListNode(num % 10);
      l1 = l1->next;
      l2 = l2->next;
    }
    if (!l1)
      swap(l1, l2);
    while (l1) {
      int num = carry + l1->val;
      carry = num / 10;
      next = next->next = new ListNode(num % 10);
      l1 = l1->next;
    }
    if (carry) {
      next = next->next = new ListNode(carry);
    }
    return root->next;
  }
};
// @lc code=end

// [1,2,3]\n[0,1]
// [0,0,1]\n[0,1]
