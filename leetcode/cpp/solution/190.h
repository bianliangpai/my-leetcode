#pragma once
#include "leetcode.h"

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (uint32_t i = 0; i < 31; i++) {
      result += (n & 1);
      n >>= 1;
      result <<= 1;
    }
    result += n;

    return result;
  }
};

int Leetcode() {
  uint32_t num = 1;
  Solution S;

  uint32_t result = S.reverseBits(num);

  return 0;
}