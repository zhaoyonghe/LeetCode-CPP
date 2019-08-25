// 8, 100.00

#include<cstddef>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe) {
		if (is > ie) {
			return NULL;
		}

		int rootVal = postorder[pe];

		TreeNode* root = new TreeNode(rootVal);

		int i = 0;
		for (i = is; i <= ie; i++) {
			if (inorder[i] == rootVal) {
				break;
			}
		}

		root -> left = buildTree(inorder, postorder, is, i - 1, ps, ps + i - is - 1);
		root -> right = buildTree(inorder, postorder, i + 1, ie, ps + i - is, pe - 1);

		return root;
	}
};