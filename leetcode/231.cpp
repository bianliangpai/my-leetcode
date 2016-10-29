//#include "leetcode.h"
//
//class Solution {
//public:
//	bool isPowerOfTwo(int n) {
//		if (n <= 0)
//			return false;
//
//		uint32_t cnt = 0;
//		for (int i = 0; i < 31; i++)
//		{
//			cnt += (n & 1);
//			n >>= 1;
//		}
//		cnt += n;
//
//		if (cnt == 1)
//			return true;
//		else return false;
//	}
//};
//
//int main()
//{
//	Solution S;
//
//	bool result = S.isPowerOfTwo(1);
//
//	return 0;
//}