// 20, 97.65

#include<cstddef>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    int i = 0;
    int result = -1;
    int kthSmallest(TreeNode* root, int k) {
        preorder(root, k);
        return result;
    }

    void preorder(TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }

        preorder(root -> left, k);
        if (i == k) {
            return;
        }

        i += 1;
        if (i == k) {
            result = root -> val;
            return;
        }

        preorder(root -> right, k);
        // if(i == k) return;
    }


};