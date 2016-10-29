//#include "leetcode.h"
//
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		vector<uint32_t> cnt(32);
//		
//		/* statistic all the num by bit */
//		for (int i = 0; i < nums.size(); i++)
//		{
//			uint32_t t_cnt = 0;
//			uint32_t num = nums[i];
//			while (num != 0)
//			{
//				cnt[t_cnt++] += (num & 1);
//				num >>= 1;
//			}
//		}
//
//		/* if $(num in nums) % 3 == 1, return num */
//		int result = 0;
//		for (int i = 0; i < 32; i++)
//		{
//			if (cnt[i] % 3 != 0)
//			{
//				result |= (1 << i);
//			}
//		}
//
//		return result;
//	}
//};
//
//int main()
//{
//	Solution S;
//	vector<int> vec = { -2, -2, 1, 1, -3, 1, -3, -3, -4, -2 };
//
//	int result = S.singleNumber(vec);
//
//	return 0;
//}