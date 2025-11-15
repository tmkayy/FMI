#include <string>
#include <stack>
#include <vector>
#include <queue>

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
	bool isValidBST(TreeNode* root) {
		return isNodeValid(root);
	}

	bool isNodeValid(TreeNode* root, long long upper = LLONG_MAX, long long lower = LLONG_MIN) {
		if (!root)
			return true;
		if (root->val >= upper || root->val <= lower)
			return false;

		return isNodeValid(root->left, root->val, lower) && isNodeValid(root->right, upper, root->val);
	}
};