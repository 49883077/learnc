#include "TreeNode.h"
/*
简单方法，一列一列比较
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result = "";
		if (strs.size() == 0)
		{
			return result;
		}
		for (int i = 0; i < strs[0].size(); i++)
		{
			int j = 1;
			for (; j < strs.size() ;j++)
			{
				if (strs[j][i] != strs[0][i])
				{
					return result;
				}
			}
			if (j == strs.size())
			{
				result += strs[0][i];
			}
		}
		return result;
	}
};