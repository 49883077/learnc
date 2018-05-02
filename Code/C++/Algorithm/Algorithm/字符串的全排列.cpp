#include "TreeNode.h"

class Solution {
public:
	void CalcAllPermutation(char* perm, int from, int to)
	{
		if (to <= 1)
		{
			return;
		}

		if (from == to)
		{
			for (int i = 0; i <= to; i++)
				cout << perm[i];
			cout << endl;
		}
		else
		{
			for (int j = from; j <= to; j++)
			{
				swap(perm[j], perm[from]);
				CalcAllPermutation(perm, from + 1, to);
				swap(perm[j], perm[from]);
			}
		}
	}
};

void main1002()
{
	char str[] ="abc";
	Solution s;
	s.CalcAllPermutation(str,0,2);
	system("pause");
}