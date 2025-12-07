#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> h;
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            h[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& s : h)
            res.push_back(s.second);
        return res;
    }
};