#pragma once
#include <cmath>
#include <utility>

#include "leetcode.h"

class Solution {
 private:
  using ST = std::size_t;
  using ET = int;
  using MT = float;
  using MIT = float;

  class SortedVectorView {
   public:
    struct iterator {
     private:
      using InnerIt = typename std::vector<ET>::iterator;

     public:
      iterator(InnerIt&& iit, ST idx) : iit_{std::move(iit)}, idx_{idx} {}
      iterator operator+(ST n) const { return iterator(iit_ + n, idx_ + n); }
      iterator& operator++() {
        ++idx_;
        ++iit_;
        return *this;
      }

      bool operator!=(iterator const& other) const {
        return iit_ != other.iit_;
      }

      decltype(auto) operator*() const {
        return std::pair<ET, ST>{*iit_, idx_};
      }

     private:
      ST idx_;
      InnerIt iit_;
    };

   public:
    SortedVectorView(std::vector<ET>& vec)
        : beg_{0}, end_{vec.size() - 1}, sv_{vec} {
      Update();
    }

    ST size() const { return end_ - beg_ + 1; }

    iterator begin() { return iterator(sv_.begin() + beg_, beg_); }
    iterator end() { return iterator(sv_.begin() + end_ + 1, end_ + 1); }

    bool Ok() const { return beg_ + 1 < end_; }

    MT Mid() const {
      if (odd_) {
        return static_cast<MT>(sv_[(beg_ + end_) / 2]);
      } else {
        ST tmp = (beg_ + end_) / 2;
        return static_cast<MT>((sv_[tmp] + sv_[tmp + 1]) / 2);
      }
    }
    MIT MidIdx() const {
      if (odd_) {
        return (beg_ + end_) / 2;
      } else {
        ST tmp = (beg_ + end_) / 2;
        return static_cast<float>(tmp + tmp + 1) / 2;
      }
    }

    void LShrink() {
      end_ = odd_ ? ((beg_ + end_) / 2) : ((beg_ + end_) / 2 + 1);
      Update();
    }
    void RShrink() {
      beg_ = (beg_ + end_) / 2;
      Update();
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    SortedVectorView const& svv) {
      for (auto it = svv.beg_; it <= svv.end_; ++it) {
        os << svv.sv_[it] << " ";
      }
      return os;
    }

   private:
    void Update() { odd_ = (end_ - beg_) % 2 == 0; }

   private:
    ST beg_, end_;
    bool odd_;
    std::vector<ET>& sv_;
  };
  using SVV = SortedVectorView;

 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    // Step1. Initialize
    SVV v1{nums1};
    SVV v2{nums2};

    // Step2. Find candidates
    while (v1.Ok() || v2.Ok()) {
      if (v1.Mid() <= v2.Mid()) {
        v1.RShrink();
        v2.LShrink();
      } else {
        v1.LShrink();
        v2.RShrink();
      }
    }

    // Step3. Get result
    // maximum number of candidates is four
    constexpr ST max_candidates = 4;

    std::vector<std::pair<ET, ST>> candidates{};
    candidates.resize(max_candidates);
    std::transform(
        v1.begin(), v1.end(), candidates.begin(),
        [this, &nums1](std::pair<ET, ST> const& pair) -> std::pair<ET, ST> {
          std::pair<ET, ST> result(pair.first,
                                   CalcDiffToMedian(nums1, pair.second));
          return result;
        });
    std::transform(
        v2.begin(), v2.end(), candidates.begin() + v1.size(),
        [this, &nums2](std::pair<ET, ST> const& pair) -> std::pair<ET, ST> {
          std::pair<ET, ST> result(pair.first,
                                   CalcDiffToMedian(nums2, pair.second));
          return result;
        });

    // TODO: meaningless sort
    std::sort(candidates.begin(), candidates.end(),
              [](std::pair<ET, ST> const& lhs, std::pair<ET, ST> const& rhs) {
                return lhs.first < rhs.first;
              });

    ST sz = candidates.size();
    if ((nums1.size() + nums2.size()) % 2 == 1) {
      return candidates[sz / 2 - 1].first;
    } else {
      return (candidates[sz / 2].first + candidates[sz / 2 - 1].first) / 2.0;
    }
  }

 private:
  ST CalcDiffToMedian(std::vector<int> const& nums, ST index) const {
    return std::abs(static_cast<int>((index + 1) - (nums.size() - 1 - index)));
  }
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