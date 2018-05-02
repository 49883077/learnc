#include "TreeNode.h"

//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<string> _stack;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i].compare("+") == 0 || tokens[i].compare("-") == 0 || tokens[i].compare("*") == 0 || tokens[i].compare("/") == 0)
			{
				int operation1 = stoi(_stack.top());
				_stack.pop();
				int operation2 = stoi(_stack.top());
				_stack.pop();
				if (tokens[i].compare("+") == 0)
				{
					_stack.push(to_string(operation1 + operation2));
				}
				else if (tokens[i].compare("-") == 0)
				{
					_stack.push(to_string(operation1 - operation2));

				}
				else if (tokens[i].compare("*") == 0)
				{
					_stack.push(to_string(operation1 * operation2));

				}

				else if (tokens[i].compare("/") == 0)
				{
					_stack.push(to_string(operation2 / operation1));

				}
			}
			else
			{
				_stack.push(tokens[i]);
				cout << tokens[i].c_str();
			}
		}
		int result = stoi(_stack.top());
		return result;
	}
};

void main150()
{
	Solution s;
	vector<string> tokens = { "-3", "9", "*"};
	int result = s.evalRPN(tokens);
	cout << result << endl;
	system("pause");
}
