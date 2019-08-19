// 4, 84.12

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == NULL) {
            return result;
        }

        vector<TreeNode*> nodeStack;

        nodeStack.push_back(root);

        while (nodeStack.size() > 0) {
            TreeNode* node = nodeStack.back();

            nodeStack.pop_back();

            result.push_back(node -> val);

            if (node -> right != NULL) {
                nodeStack.push_back(node -> right);
            }

            if (node -> left != NULL) {
                nodeStack.push_back(node -> left);
            }

        }

        return result;
    }
};