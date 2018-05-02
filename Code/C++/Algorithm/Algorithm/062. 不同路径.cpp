#include "TreeNode.h"
class Solution {
public:
	int uniquePaths(int m, int n) {
		int col = m;
		int row = n;

		vector<vector<int>> dp(row, vector<int>(col));
		dp[0][0] = 1;
		for (size_t i = 1; i < row; i++)
		{
			dp[i][0] = 1;
		}

		for (size_t i = 1; i < col; i++)
		{
			dp[0][i] = 1;
		}

		for (size_t i = 1; i < row; i++)
		{
			for (size_t j = 1; j < col; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[row-1][col-1];
	}
};

void main062()
{

	Solution s;
	s.uniquePaths(3, 2);

}