#include "TreeNode.h"
#include <assert.h>
char* mystrcpy(char *dst, const char *src)
{	
	assert((NULL != dst) && (NULL != src));
	char* ret = dst;

	while ((*dst++ = *src++) != '\0');
	
	return ret;
}
void main()
{
	char* s1 = "sss";
	char* s2 = "sss cc";
	char* ret = mystrcpy(s1, s2);
	//cout << res;
	system("pause");
}
