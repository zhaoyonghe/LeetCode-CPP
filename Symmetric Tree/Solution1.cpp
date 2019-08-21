// 12, 42.91

#include<cstddef>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	bool isSymmetric(TreeNode* root) {
		return root == NULL ? true : isSymmetric(root -> left, root -> right);
	}

	bool isSymmetric(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) {
			return true;
		}

		if (p == NULL || q == NULL) {
			return false;
		}

		if (p -> val != q -> val) {
			return false;
		}

		return isSymmetric(p -> left, q -> right) && isSymmetric(p -> right, q -> left);
	}
};