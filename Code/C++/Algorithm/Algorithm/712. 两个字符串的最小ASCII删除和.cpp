#include "TreeNode.h"
class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int size1 = s1.size();
		int size2 = s2.size();
		int len = size1 < size2 ? size1 : size2;
		int i = 0;
		int j = 0;
		int sum = 0;
		for (; i < len && j < len;)
		{
			if (s1[i] < s2[j])
			{
				sum += s1[i];
				i++;
			}
			else if (s1[i] > s2[j]){
				sum += s2[j];
				j++;
			}
			else
			{
				i++;
				j++;
			}
			cout << "i=" << i <<endl;
			cout << "j=" << j <<endl;
		}

		for (; i < size1; i++)
		{
			sum += s1[i];
		}

		for (; j < size2; j++)
		{
			sum += s2[j];
		}
		return sum;
	}

	int minimumDeleteSum2(string s1, string s2) {
		//DP
		int m = s1.size(), n = s2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int j = 1; j <= n; j++)
			dp[0][j] = dp[0][j - 1] + s2[j - 1];
		for (int i = 1; i <= m; i++) {
			dp[i][0] = dp[i - 1][0] + s1[i - 1];
			for (int j = 1; j <= n; j++) {
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
			}
		}
		return dp[m][n];
	}

};

void main()
{
	//string s1 = "igijekdtywibepwonjbwykkqmrgmtybwhwjiqudxmnniskqjfbkpcxukrablqmwjndlhblxflgehddrvwfacarwkcpmcfqnajqfxyqwiugztocqzuikamtvmbjrypfqvzqiwooewpzcpwhdejmuahqtukistxgfafrymoaodtluaexucnndlnpeszdfsvfofdylcicrrevjggasrgdhwdgjwcchyanodmzmuqeupnpnsmdkcfszznklqjhjqaboikughrnxxggbfyjriuvdsusvmhiaszicfa";
	//string s2 = "ikhuivqorirphlzqgcruwirpewbjgrjtugwpnkbrdfufjsmgzzjespzdcdjcoioaqybciofdzbdieegetnogoibbwfielwungehetanktjqjrddkrnsxvdmehaeyrpzxrxkhlepdgpwhgpnaatkzbxbnopecfkxoekcdntjyrmmvppcxcgquhomcsltiqzqzmkloomvfayxhawlyqxnsbyskjtzxiyrsaobbnjpgzmetpqvscyycutdkpjpzfokvi";

	string s1 = "sea";
	string s2 = "eat";

	Solution s;
	s.minimumDeleteSum2(s1,s2);

}