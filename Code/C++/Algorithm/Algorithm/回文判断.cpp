#include "TreeNode.h"

class Solution {
public:
	bool Palindrome(string str) {
		if (str.empty() || str.size() == 1)
		{
			return true;
		}

		int first;
		int second;

		int size = str.size();
		int middle = (size >> 1) - 1 >= 0 ? (size >> 1) - 1 : 0;
		first = middle;
		second = size - 1 - middle;

		while (first >= 0)
		{
			if (str[first] != str[second])
			{
				return false;
			}

			first--;
			second++;
		}
		return true;

	}
};

void main1001()
{
	string str = "abccba";
	Solution s;
	s.Palindrome(str);

}