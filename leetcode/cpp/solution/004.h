#pragma once
#include "leetcode.h"

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    return 0.0;
  }
};

int Leetcode() {
  Solution S;
  std::vector<int> nums1({1, 3, 5, 7, 9});
  std::vector<int> nums2({2, 4, 6, 8, 10});
  int length = S.findMedianSortedArrays(nums1, nums2);

  std::cout << '\n';
  return 0;
}