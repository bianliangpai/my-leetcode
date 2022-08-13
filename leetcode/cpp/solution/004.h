#pragma once

#include "leetcode.h"

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    std::size_t total_sz{nums1.size() + nums2.size()};
    merged_nums.reserve(total_sz);
    typename std::vector<int>::iterator i1{nums1.begin()}, i2{nums2.begin()};
    while (i1 != nums1.end() || i2 != nums2.end()) {
      if (i1 == nums1.end()) {
        merged_nums.push_back(*i2++);
      } else if (i2 == nums2.end()) {
        merged_nums.push_back(*i1++);
      } else {
        int tmp{*i1 < *i2 ? (*i1++) : (*i2++)};
        merged_nums.push_back(tmp);
      }
    }
    bool is_odd{total_sz % 2 != 0};
    return is_odd
               ? merged_nums[total_sz / 2]
               : (merged_nums[total_sz / 2 - 1] + merged_nums[total_sz / 2]) /
                     2.0;
  }

 private:
  std::vector<int> merged_nums;
};

void Case1() {
  Solution S;

  std::vector<int> nums1({1, 3, 13});
  std::vector<int> nums2({2, 5, 7, 8, 10});
  int median = S.findMedianSortedArrays(nums1, nums2);
  std::cout << median << std::endl;
}
void Case2() {
  Solution S;

  std::vector<int> nums1({1, 4, 20, 105});
  std::vector<int> nums2({2, 5, 7, 100, 101});
  int median = S.findMedianSortedArrays(nums1, nums2);
  std::cout << median << std::endl;
}
void Case3() {
  Solution S;

  std::vector<int> nums1({1, 4, 7, 105});
  std::vector<int> nums2({2, 5, 20, 100, 101});
  int median = S.findMedianSortedArrays(nums1, nums2);
  std::cout << median << std::endl;
}
void Case4() {
  Solution S;

  std::vector<int> nums1({1, 2, 3, 4});
  std::vector<int> nums2({5, 6, 7, 8, 9});
  int median = S.findMedianSortedArrays(nums1, nums2);
  std::cout << median << std::endl;
}
void Case5() {
  Solution S;

  std::vector<int> nums1({1});
  std::vector<int> nums2({5});
  int median = S.findMedianSortedArrays(nums1, nums2);
  std::cout << median << std::endl;
}

int Leetcode() {
  Case1();
  Case2();
  Case3();
  Case4();
  Case5();
  return 0;
}