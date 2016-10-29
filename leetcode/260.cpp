#include "leetcode.h"

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> result(2, 0);

		

		return result;
	}
};

int main()
{
	Solution S;
	vector<int> nums;
	for (int times = 0; times < 2; times++)
	{
		for (int i = 0; i < 10; i++)
		{
			nums.push_back(i);
		}
	}
	nums.push_back(11);
	nums.push_back(12);

	S.singleNumber(nums);

	return 0;
}