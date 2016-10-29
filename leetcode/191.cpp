//#include "leetcode.h"
//
//class Solution {
//public:
//	int hammingWeight(uint32_t n) {
//		int result = 0;
//		while (n != 0)
//		{
//			result += (n & 1);
//			n >>= 1;
//		}
//
//		return result;
//	}
//};
//
//int main()
//{
//	uint32_t num = 11;
//	Solution S;
//
//	uint32_t result = S.hammingWeight(num);
//
//	return 0;
//}