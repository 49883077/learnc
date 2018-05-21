#include "TreeNode.h"
#include <assert.h>
int mystrcmp(const char* s1, const char* s2)
{
	assert((NULL != s1) && (NULL != s2));
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
void main1006()
{
	const char* s1 = "sss";
	const char* s2 = "sss cc";
	int res = mystrcmp(s1, s2);
	cout << res;
	system("pause");
}
