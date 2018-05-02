#include "TreeNode.h"

class Solution {
public:
	int target = 0; 
	int queen[100];
	int result = 0;

	int totalNQueens(int n) {
		target = n ;
		NQueens(0);
		return result;
	}

	void NQueens(int k)
	{
		if (k == target)
		{
			/* 051
			for (int i = 0; i < target;i++)
			{
				cout << queen[i];
			}
			cout << endl;
			result++;
			*/

			//052
			vector<string> temp;
			for (int i = 0; i < target; i++)
			{
				string str;
				for (int j = 0; j < target; j++)
				{
					if (j == queen[i])
					{
						str.append("Q");
					}
					else
					{
						str.append(".");
					}

				}
				temp.push_back(str);
			}
			res2.push_back(temp);

			return;
		}

		for (int i = 0; i < target ; i++)
		{
			int j ;
			for (j = 0; j < k;j++)
			{
				if ( i == queen[j] || ( abs(i - queen[j]) == abs(k - j)))
				{
					break;
				}
			}

			if (j == k)
			{
				queen[k] = i;
				NQueens(k + 1);
			}
		}
	}
	vector<vector<string>> res2;
	vector<vector<string>> solveNQueens(int n) {
		target = n;
		NQueens(0);
		return res2;
	}

};


void main052()
{
	Solution s;
	vector<vector<string>> res2 = s.solveNQueens(4);

	system("pause");
}


