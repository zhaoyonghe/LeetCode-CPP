// 16, 97.78

#include<cstddef>
#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 {
public:

	int rob(TreeNode* root) {
		int* result = maxRob(root);
		return max(result[0], result[1]);
	}

	int* maxRob(TreeNode* root) {
		int* result = new int[2];
		result[0] = 0;
		result[1] = 0;
		if (root == NULL) {
			return result;
		}

		int* leftResult = maxRob(root -> left);
		int* rightResult = maxRob(root -> right);

		// not rob this node
		result[0] = max(leftResult[0], leftResult[1]) + max(rightResult[0], rightResult[1]);

		// rob this node
		result[1] = root -> val + leftResult[0] + rightResult[0];

		return result;
	}
};