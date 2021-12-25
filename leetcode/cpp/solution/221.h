#ifndef LEETCODE_CPP_SOLUTION_221
#define LEETCODE_CPP_SOLUTION_221

#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

// 1.
// 要验证某个区域为正方形，没有什么操作比直接逐一判断所有位置的元素是否都为"1"复杂度更低
// 故本题的优化点只能是如何少做判断，而不是如何找到其他的方式
// 2.
// 无需尝试保存某个位置是否为"1"的信息，因为没有什么方式比再通过索引查询一次复杂度更低
// 3.
// 验证正方形时需要按边长从小到大验证
// 4.
// 当剩余部分的长度已经小于当前最大正方形边长时，就可以停止搜索
class Solution {
 private:
  using SizeT = std::size_t;

 public:
  Solution() : maxl_{0} {}

  int maximalSquare(std::vector<std::vector<char>>& matrix) {
    std::vector<std::vector<char>>& m_ = matrix;
    SizeT h = m_.size();
    SizeT w = m_[0].size();

    for (SizeT y = 0; y < h - maxl_; ++y) {
      for (SizeT x = 0; x < w - maxl_; ++x) {
        SizeT l = 0;
        while (y + l < h && x + l < w && IsSquare(m_, y, x, l)) {
          ++l;
        };
        maxl_ = std::max(maxl_, l);
      }
    }

    return maxl_ * maxl_;
  }

 private:
  bool IsSquare(std::vector<std::vector<char>>& m_, SizeT y, SizeT x,
                SizeT offset) {
    return IsSquare(m_, y, x, offset, offset);
  }
  bool IsSquare(std::vector<std::vector<char>>& m_, SizeT y, SizeT x,
                SizeT min_offset, SizeT max_offset) {
    assert(max_offset >= min_offset);

    for (SizeT offset = min_offset; offset <= max_offset; ++offset) {
      for (SizeT tmpx = x; tmpx <= x + offset; ++tmpx) {
        if (m_[y + offset][tmpx] == '0') {
          return false;
        }
      }
      for (SizeT tmpy = y; tmpy <= y + offset; ++tmpy) {
        if (m_[tmpy][x + offset] == '0') {
          return false;
        }
      }
    }

    return true;
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

int Leetcode() {
  Case1();
  Case2();
  Case3();
  return 0;
}

#endif /* LEETCODE_CPP_SOLUTION_221 */
