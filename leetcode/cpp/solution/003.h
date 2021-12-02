#pragma once
#include "leetcode.h"

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    std::string longest, now;
    for (auto i : s) {
      size_t t_position = now.find(i);
      if (t_position < s.size()) {
        if (now.size() > longest.size()) longest = now;
        now = now.substr(t_position + 1, now.size());
      }
      now += i;
    }
    if (now.size() > longest.size()) longest = now;

    return int(longest.size());
  }
};

int Leetcode() {
  Solution S;
  std::string str = "vdvf";
  int length = S.lengthOfLongestSubstring(str);

  std::cout << '\n';
  return 0;
}