// 12, 96.76

#include<cstddef>
#include<algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }

    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = getHeight(root -> left);

        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = getHeight(root -> right);

        if (rightHeight == -1) {
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
        }

    }
};