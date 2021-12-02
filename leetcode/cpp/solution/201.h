#pragma once
#include "leetcode.h"

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    uint32_t um = m;
    uint32_t un = n;

    uint32_t result = 0;
    for (int i = 31; i >= 0; i--) {
      uint32_t t_mask = pow(2, i);
      if (t_mask & un) {
        if (t_mask & um) {
          result += t_mask;
        } else
          return result;
      }
    }

    return result;
  }
};

int Leetcode() {
  Solution S;

  int result = S.rangeBitwiseAnd(5, 7);

  return 0;
}