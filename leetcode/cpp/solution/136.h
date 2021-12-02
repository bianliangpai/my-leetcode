#pragma once
#include "leetcode.h"

class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    int x = 0;
    for (auto i : nums) x ^= i;
    return x;
  }
};

int Leetcode() {
  Solution S;
  std::vector<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
    vec.push_back(10 - i);
  }
  vec.push_back(10);
  S.singleNumber(vec);

  return 0;
}