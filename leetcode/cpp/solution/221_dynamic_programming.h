#ifndef LEETCODE_CPP_SOLUTION_221
#define LEETCODE_CPP_SOLUTION_221

#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T>
T Min(T t1, T t2, T t3) {
  return std::min(t1, std::min(t2, t3));
}

class Solution {
 private:
  using SizeT = std::size_t;

 public:
  Solution() : maxl_{0} {}

  int maximalSquare(std::vector<std::vector<char>>& matrix) {
    std::vector<std::vector<char>>& m_ = matrix;
    SizeT h = m_.size();
    SizeT w = m_[0].size();

    std::vector<SizeT> dp(h * w, 0);
    for (SizeT y = 0; y < h; ++y) {
      for (SizeT x = 0; x < w; ++x) {
        SizeT last_y = y == 0 ? 0 : dp[(y - 1) * w + x];
        SizeT last_x = x == 0 ? 0 : dp[y * w + (x - 1)];
        SizeT last_xy = (x == 0 || y == 0) ? 0 : dp[(y - 1) * w + (x - 1)];

        SizeT current = m_[y][x] == '1' ? 1 : 0;
        SizeT tmp = current == 1 ? Min(last_y, last_x, last_xy) + current : 0;
        dp[y * w + x] = tmp;
        maxl_ = tmp > maxl_ ? tmp : maxl_;

        // for (SizeT y = 0; y < h; ++y) {
        //   for (SizeT x = 0; x < w; ++x) {
        //     std::cout << dp[y * w + x] << " ";
        //   }
        //   std::cout << std::endl;
        // }
        // std::cout << std::endl;
      }
    }

    return maxl_ * maxl_;
  }

 private:
  SizeT maxl_;
};

void Case1() {
  Solution S;
  std::vector<std::vector<char>> m = {{'1', '0', '1', '0', '0'},
                                      {'1', '0', '1', '1', '1'},
                                      {'1', '1', '1', '1', '1'},
                                      {'1', '0', '0', '1', '0'}};
  std::cout << S.maximalSquare(m) << std::endl;
}
void Case2() {
  Solution S;
  std::vector<std::vector<char>> m = {{'0', '1'}, {'1', '0'}};
  std::cout << S.maximalSquare(m) << std::endl;
}
void Case3() {
  Solution S;
  std::vector<std::vector<char>> m = {{'0'}};
  std::cout << S.maximalSquare(m) << std::endl;
}
void Case4() {
  Solution S;
  std::vector<std::vector<char>> m = {{'1', '1'}, {'1', '1'}};
  std::cout << S.maximalSquare(m) << std::endl;
}
void Case5() {
  Solution S;
  std::vector<std::vector<char>> m = {
      // clang-format off
      {'1', '0', '1', '1', '0', '1'},
      {'1', '1', '1', '1', '1', '1'},
      {'0', '1', '1', '0', '1', '1'},
      {'1', '1', '1', '0', '1', '0'},
      {'0', '1', '1', '1', '1', '1'},
      {'1', '1', '0', '1', '1', '1'}};
  // clang-format on
  std::cout << S.maximalSquare(m) << std::endl;
}

int Leetcode() {
  Case1();
  Case2();
  Case3();
  Case4();
  Case5();
  return 0;
}

#endif /* LEETCODE_CPP_SOLUTION_221 */
