#pragma once
#include "leetcode.h"

class Solution {
 public:
  std::vector<int> singleNumber(std::vector<int>& nums) {
    std::vector<int> result(2, 0);

    return result;
  }
};

int Leetcode() {
  Solution S;
  std::vector<int> nums;
  for (int times = 0; times < 2; times++) {
    for (int i = 0; i < 10; i++) {
      nums.push_back(i);
    }
  }
  nums.push_back(11);
  nums.push_back(12);

  S.singleNumber(nums);

  return 0;
}