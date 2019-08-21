// 12, 87.09

#include<cstddef>
#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}

		return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
	}
};