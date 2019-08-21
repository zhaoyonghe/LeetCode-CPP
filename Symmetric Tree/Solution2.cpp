// 12, 42.91

#include<cstddef>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        queue<TreeNode*> left;
        queue<TreeNode*> right;

        left.push(root -> left);
        right.push(root -> right);

        while (!left.empty()) {
            TreeNode* p = left.front();
            TreeNode* q = right.front();

            left.pop();
            right.pop();

            if (p == NULL && q == NULL) {
                continue;
            }

            if (p == NULL || q == NULL) {
                return false;
            }

            if (p -> val != q -> val) {
                return false;
            }

            left.push(p -> left);
            left.push(p -> right);

            right.push(q -> right);
            right.push(q -> left);
        }

        return true;
    }
};