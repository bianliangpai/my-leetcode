#pragma once
#include "leetcode.h"

class Solution {
 public:
  void QuickSort(std::vector<int>::iterator x, int numsize, int start) {
    if (numsize > 1) {
      int i = 0, j = numsize - 1;
      int val = *x;
      int tempos = pos[start];
      while (i < j) {
        for (; j > i; j--)
          if (*(x + j) < val) {
            *(x + i) = *(x + j);
            pos[start + i] = pos[start + j];
            i++;
            break;
          }
        for (; i < j; i++)
          if (*(x + i) > val) {
            *(x + j) = *(x + i);
            pos[start + j] = pos[start + i];
            j--;
            break;
          }
      }
      *(x + i) = val;
      pos[start + i] = tempos;
      QuickSort(x, i, start);
      QuickSort(x + i + 1, numsize - i - 1, start + i + 1);
    }
  }

  int findnum(std::vector<int>& nums, int num, int start) {
    int b = start;
    int e = nums.size() - 1;
    while (b < e) {
      if (num == nums[b]) return b + 1;
      if (num == nums[e]) return e + 1;

      if (num > ((nums[b] + nums[e]) / 2))
        b = (e + b) / 2 + 1;
      else
        e = (e + b) / 2;
    }
    return 0;
  }

  // std::vector<int> twoSum(std::vector<int>& nums, int target) {
  //	int position;
  //	pos = nums;
  //	cop = nums;
  //	for (int i = 0; i < pos.size(); i++) pos[i] = i;

  //	QuickSort(begin(cop), cop.size(), 0);
  //	int p1, p2;
  //	for (int i = 0; i < cop.size(); i++) {
  //		if (position = findnum(cop, target - cop[i], i)) {
  //			if (i == position-1) position++;
  //			if (pos[i] < pos[position]){
  //				p1 = pos[i];
  //				p2 = pos[position-1];
  //			}
  //			else{
  //				p2 = pos[i];
  //				p1 = pos[position-1];
  //			}
  //			std::vector<int> result({ p1, p2 });
  //			return result;
  //		}
  //	}
  //	return{ 0, 0 };
  //}

  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> position;
    for (int i = 0; i < nums.size(); i++) position[nums[i]] = i;
    for (int i = 0; i < nums.size(); i++)
      if (position.end() != position.find(target - nums[i]) &&
          i != position[target - nums[i]])
        return {position[nums[i]], position[target - nums[i]]};
    return {0, 0};
  }

 private:
  std::vector<int> pos;
  std::vector<int> cop;
};

int Leetcode() {
  Solution S;
  std::vector<int> nums({0, 4, 3, 0});
  int target = 0;
  std::vector<int> result = S.twoSum(nums, target);

  for (auto num : result) {
    std::cout << num << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
