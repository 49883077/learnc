#include "TreeNode.h"
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res(numRows, vector<int>());

		for (int i = 0; i < numRows; i++)
		{
			vector<int> temp(i + 1, 0);
			for (int j = 0; j <= i; j++)
			{
				cout << i << "  " << j << endl;
				if (j == 0 || j == i)
				{
					temp[j] = 1;
				}
				else
				{
					int val = res[i - 1][j] + res[i - 1][j - 1];
					temp[j] = val;
				}

			}
			res[i] = temp;
		}
		return res;
	}
};

void main118()
{
	Solution s;
	vector<vector<int>> res2 = s.generate(0);

	system("pause");
}

