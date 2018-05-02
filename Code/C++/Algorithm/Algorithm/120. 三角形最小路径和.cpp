#include "TreeNode.h"

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row = triangle.size();
		vector<int> minTrangls(triangle[row - 1].size());

		int size = triangle[row - 1].size();
		for (int j = 0; j < size; j++)
		{
			minTrangls[j] = triangle[row - 1][j];
		}

		for (int i = row - 2; i >= 0; i--)
		{
			int size = triangle[i].size();
			for (int j = 0; j < size; j++)
			{
				minTrangls[j] = min(minTrangls[j],minTrangls[j+1]) + triangle[i][j];
			}
		}
		return minTrangls[0];
	}
};

void main120()
{
	vector<vector<int>> grid{
		{ 2, },
		{ 3, 4 },
		{ 6, 5, 7 },
		{ 4, 1, 8, 3 }
};
	Solution s;
	s.minimumTotal(grid);

}