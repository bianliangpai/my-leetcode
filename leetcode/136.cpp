//#include "leetcode.h"
//
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int x = 0;
//		for (auto i : nums)
//			x ^= i;
//		return x;
//	}
//};
//
//int main()
//{
//	Solution S;
//	vector<int> vec;
//	for (int i = 0; i < 10; i++)
//	{
//		vec.push_back(i);
//		vec.push_back(10 - i);
//	}
//	vec.push_back(10);
//	S.singleNumber(vec);
//	
//	return 0;
//}