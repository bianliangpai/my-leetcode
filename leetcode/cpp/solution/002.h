#pragma once
#include "leetcode.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l3 = new ListNode(0);
    ListNode* pre = new ListNode(0);
    pre->next = l3;

    int carry_bit(0);
    while (l1 != NULL || l2 != NULL) {
      if (l1 == NULL) l1 = new ListNode(0);
      if (l2 == NULL) l2 = new ListNode(0);
      int temp = l1->val + l2->val + l3->val;
      if (temp >= 10) {
        l3->val = (temp - 10);
        carry_bit = 1;
      } else
        l3->val = temp;
      l2 = l2->next;
      l1 = l1->next;
      if (carry_bit || l1 != NULL || l2 != NULL) {
        if (l3->next == NULL) l3->next = new ListNode(carry_bit);
        carry_bit = 0;
        l3 = l3->next;
      }
    }
    return pre->next;
  }
};

int Leetcode() {
  ListNode l1(9), l2(1);
  l1.next = new ListNode(8);
  Solution S;
  ListNode* res = S.addTwoNumbers(&l1, &l2);

  std::cout << std::endl;
  return 0;
}