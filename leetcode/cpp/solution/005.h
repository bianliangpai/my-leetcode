#ifndef LEETCODE_CPP_SOLUTION_005
#define LEETCODE_CPP_SOLUTION_005

#include <iostream>
#include <string>
#include <tuple>

class Solution {
 public:
  std::string longestPalindrome(std::string s) {
    std::size_t start{std::string::npos};
    std::size_t length{0};
    for (std::size_t pos = 0; pos < s.length(); ++pos) {
      std::pair<std::size_t, std::size_t> result = Calc(s, pos);
      if (result.second > length) {
        start = static_cast<std::size_t>(result.first);
        length = static_cast<std::size_t>(result.second);
      }
    }
    return s.substr(start, length);
  }

 private:
  std::pair<std::size_t, std::size_t> Calc(const std::string& s,
                                           std::size_t pos) {
    std::int64_t l_pos = static_cast<std::int64_t>(pos);
    std::int64_t r_pos = static_cast<std::int64_t>(pos);
    while (r_pos != s.size() - 1 && s[r_pos] == s[r_pos + 1]) {
      ++r_pos;
    }

    while (l_pos >= 0 && r_pos < s.size()) {
      std::int64_t l_tmp = l_pos - 1;
      std::int64_t r_tmp = r_pos + 1;
      if (l_tmp >= 0 && r_tmp < s.size()) {
        if (s[l_tmp] != s[r_tmp]) {
          break;
        } else {
          --l_pos;
          ++r_pos;
        }
      } else {
        break;
      }
    }
    return {l_pos, r_pos - l_pos + 1};
  }
};

int Leetcode() {
  Solution S;

  std::cout << S.longestPalindrome("babad") << std::endl;
  std::cout << S.longestPalindrome("cbbd") << std::endl;
  std::cout << S.longestPalindrome("a") << std::endl;
  std::cout << S.longestPalindrome("ac") << std::endl;
  std::cout << S.longestPalindrome("ccc") << std::endl;

  return 0;
}

#endif /* LEETCODE_CPP_SOLUTION_005 */
