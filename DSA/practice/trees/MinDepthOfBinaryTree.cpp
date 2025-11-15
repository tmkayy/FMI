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
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;

		int ldeep = minDepth(root->left);
		int rdeep = minDepth(root->right);

		if (ldeep == 0)
			return 1 + rdeep;
		if (rdeep == 0)
			return 1 + ldeep;

		return 1 + min(ldeep, rdeep);
	}
};