// 16, 88.91

#include<cstddef>
#include<climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long lb, long ub) {
        if (root == NULL) {
            return true;
        }

        long val = (long) root -> val;

        if (val <= lb || ub <= val) {
            return false;
        }

        return isValidBST(root -> left, lb, val) && isValidBST(root -> right, val, ub);
    }
};