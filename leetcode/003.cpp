//#include "leetcode.h"
//
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		string longest, now;
//		for (auto i : s) {
//			size_t t_position = now.find(i);
//			if (t_position < s.size()) {
//				if (now.size() > longest.size()) 
//					longest = now;
//				now = now.substr(t_position+1, now.size());
//			}
//			now += i;
//		}
//		if (now.size() > longest.size()) longest = now;
//
//		return int(longest.size());
//	}
//};
//
//int main()
//{
//	Solution S;
//	string str = "vdvf";
//	int length = S.lengthOfLongestSubstring(str);
//	
//	cout << '\n';
//	return 0;
//}