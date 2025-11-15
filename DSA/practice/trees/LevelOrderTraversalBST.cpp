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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>res;
		if (!root)
			return res;
		queue<TreeNode*> roots;
		roots.push(root);
		while (!roots.empty()) {
			int size = roots.size();
			vector<int> level;
			for (size_t i = 0; i < size; i++)
			{
				TreeNode* node = roots.front();
				roots.pop();

				if (node->left)
					roots.push(node->left);
				if (node->right)
					roots.push(node->right);

				level.push_back(node->val);
			}
			res.push_back(level);
		}
		return res;
	}
};