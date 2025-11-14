#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> nums;
		for (string s : tokens) {
			if (s == "+" || s == "-" || s == "/" || s == "*") {
				int num2 = nums.top();
				nums.pop();
				int num1 = nums.top();
				nums.pop();
				if (s == "+")
					nums.push(num1 + num2);
				else if (s == "-")
					nums.push(num1 - num2);
				else if (s == "*")
					nums.push(num1 * num2);
				else
					nums.push(num1 / num2);
			}
			else {
				nums.push(stoi(s));
			}
		}
		if (!nums.empty()) {
			return nums.top();
		}
		return 0;
	}
};