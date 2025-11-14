#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		stack<char> s1, s2;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i] == '#') {
				if (!s1.empty())
					s1.pop();
			}
			else
				s1.push(s[i]);
		}
		for (size_t i = 0; i < t.length(); i++)
		{
			if (t[i] == '#') {
				if (!s2.empty())
					s2.pop();
			}
			else
				s2.push(t[i]);
		}
		while (!s1.empty() && !s2.empty())
		{
			if (s1.top() != s2.top())
				return false;
			s1.pop(); s2.pop();
		}

		return s1.empty() && s2.empty();
	}
};