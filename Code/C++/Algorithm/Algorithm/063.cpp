#include "TreeNode.h"
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int col = obstacleGrid[0].size();
		int row = obstacleGrid.size();

		vector<vector<int>> dp(row, vector<int>(col));
		bool rowHasOne = false;
		for (size_t i = 0; i < row; i++)
		{
			if (obstacleGrid[i][0] == 1 || rowHasOne)
			{
				dp[i][0] = 0;
				rowHasOne = true;
			}
			else
			{
				dp[i][0] = 1;
			}
		}

		bool colHasOne = false;
		for (size_t i = 0; i < col; i++)
		{
			if (obstacleGrid[0][i] == 1 || colHasOne)
			{
				dp[0][i] = 0;
				colHasOne = true;
			}
			else{
				dp[0][i] = 1;
			}		
		}

		for (size_t i = 1; i < row; i++)
		{
			for (size_t j = 1; j < col; j++)
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				
			}
		}
		return dp[row - 1][col - 1];
	}
};

void main063()
{

	Solution s;
	vector<vector<int>> obstacleGrid = {
		{ 0, 1, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	};
		s.uniquePathsWithObstacles(obstacleGrid);

}