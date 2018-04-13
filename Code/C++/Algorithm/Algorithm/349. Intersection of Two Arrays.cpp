#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> setMap;
		for (int i =0;i<nums1.size();i++)
		{
			setMap.insert(pair<int, int>(nums1[i], 0));
		}
		map<int, int>::iterator iter;
		for (int i = 0; i < nums2.size(); i++)
		{
			//setMap.insert(pair<int, int>(nums1[i], 0));
			iter = setMap.find(nums2[i]);
			if (iter!=setMap.end())
			{
				iter->second = 1;
			}
		}

		vector<int> result;
		for (iter = setMap.begin(); iter != setMap.end(); iter++)
		{
			if (iter->second > 0)
			{
				result.push_back(iter->first);
			}
		}
		return result;
	}


};

void main349()
{
	vector<int> nums1 = { 1, 2,2,2 };
	vector<int> nums2 = { 1, 2 };
	
	map<int, int> testMap;
	for (int i = 0; i < nums2.size(); i++)
	{
		testMap[i] = nums2[i];
	}
	if (testMap[1])
	{
		cout << "haha";
	}

	map<string, int> map2;

	string s1 = "aaa";
	string s2 = "abc";
	string s3 = "cba";
	
	map2[s1] = 2;
	map2[s2] = 2;
	map2[s3] = 2;

	if (map2[s1])
	{
		cout << map2[s1];
	}

	if (map2["aaa"])
	{
		cout << map2["aaa"];
	}


	string s4 = "Hello World";
	//string s5 = "H";
	for (int i = 0; i < s4.size(); i++)
	{
		string ss = s4.substr(i,1);
		cout << ss.c_str() << endl;

	}


	system("pause");
}