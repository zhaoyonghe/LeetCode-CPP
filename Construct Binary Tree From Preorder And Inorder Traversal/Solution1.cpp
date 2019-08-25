// 20, 94.73

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps > pe) {
            return NULL;
        }

        int rootVal = preorder[ps];

        TreeNode* root = new TreeNode(rootVal);

        int i = 0;
        for (i = is; i <= ie; i++) {
            if (inorder[i] == rootVal) {
                break;
            }
        }

        root -> left = buildTree(preorder, inorder, ps + 1, ps + i - is, is, i - 1);
        root -> right = buildTree(preorder, inorder, ps + 1 + i - is, pe, i + 1, ie);

        return root;
    }
};