// 0, 100.00

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == NULL) {
            return result;
        }

        vector<TreeNode*> nodeStack;
        vector<bool> unfoldStack;

        nodeStack.push_back(root);
        unfoldStack.push_back(false);

        while (nodeStack.size() > 0) {
            TreeNode* node = nodeStack.back();
            bool hasBeenUnfolded = unfoldStack.back();

            nodeStack.pop_back();
            unfoldStack.pop_back();

            if (hasBeenUnfolded) {
                result.push_back(node -> val);
            } else {
                if (node -> right != NULL) {
                    nodeStack.push_back(node -> right);
                    unfoldStack.push_back(false);
                }

                nodeStack.push_back(node);
                unfoldStack.push_back(true);

                if (node -> left != NULL) {
                    nodeStack.push_back(node -> left);
                    unfoldStack.push_back(false);
                }
            }
        }

        return result;
    }
};