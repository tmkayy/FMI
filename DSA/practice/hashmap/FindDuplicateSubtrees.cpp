#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<TreeNode*> ans;
	unordered_map<string, int> treeMap;

	string traverse(TreeNode* root) {
		if (!root)
			return "null";
		string s = to_string(root->val);
		string left = traverse(root->left);
		string right = traverse(root->right);
		string res = s + "," + left + "," + right;

		if (treeMap.find(res) != treeMap.end() && treeMap[res] == 1)
			ans.push_back(root);

		treeMap[res]++;

		return res;
	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		traverse(root);
		return ans;
	}
};