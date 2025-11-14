#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	int calPoints(vector<string>& operations) {
		stack<int> records;
		for (string s : operations) {
			if (s == "C")
				records.pop();
			else if (s=="D") {
				int record = records.top() * 2;
				records.push(record);
			}
			else if (s == "+") {
				int num1 = records.top();
				records.pop();
				int num2 = records.top() + num1;
				records.push(num1);
				records.push(num2);
			}
			else
				records.push(stoi(s));
		}
		int res = 0;
		while (!records.empty()) {
			res += records.top();
			records.pop();
		}
		return res;
	}
};