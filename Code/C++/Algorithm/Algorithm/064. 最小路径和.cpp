#include "TreeNode.h"
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int row = grid.size();//��  
		int col = grid[0].size();
		vector< vector<int> >  result(row);
		for (int i = 0; i < row; i++)
			result[i].resize(col, 0);//��������Ĵ�Сrow�У�col��   
		result[0][0] = grid[0][0];//��ʼ��      
		for (int i = 1; i < col; i++)//��ʼ����һ��  
			result[0][i] = result[0][i - 1] + grid[0][i];
		for (int i = 1; i < row; i++)//��ʼ����һ��  
			result[i][0] = result[i - 1][0] + grid[i][0];
		for (int i = 1; i < row; i++)//�����м���  
		for (int j = 1; j < col; j++)
			result[i][j] = min(result[i][j - 1] + grid[i][j], result[i - 1][j] + grid[i][j]);
		return result[row - 1][col - 1];
	}

	int minPathSum2(vector<vector<int>>& grid)
	{
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> dp(row, vector<int>(col));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < col; i++)
		{
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}

		for (int i = 1; i < row; i++)
		{
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}

		for (int i = 1; i < col; i++)
		{
			for (int j = 1; j < row; j++)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[row - 1][col - 1];
	}
};

void main064()
{
	vector<vector<int>> grid{
		{ 1, 3, 1 },
		{ 1, 5, 1 },
		{ 4, 2, 1 } };
	Solution s;
	s.minPathSum2(grid);

}