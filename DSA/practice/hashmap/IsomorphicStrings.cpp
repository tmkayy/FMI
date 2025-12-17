#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, int>h1, h2;
		int size = s.length();
		for (size_t i = 0; i < size; i++)
		{
			if (h1[s[i]] != h2[t[i]])
				return false;
			h1[s[i]] = i + 1;
			h2[t[i]] = i + 1;
		}

		return true;
	}
};