// 20, 92.40

#include<cstddef>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    unordered_map<TreeNode*, int> map;

    int rob(TreeNode* root) {
        return maxRob(root);
    }

    int maxRob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        auto it = map.find(root);
        if (it != map.end()) {
            return it -> second;
        }

        int robThis = root -> val;
        if (root -> left != NULL) {
            robThis += (maxRob(root -> left -> left) + maxRob(root -> left -> right));
        }
        if (root -> right != NULL) {
            robThis += (maxRob(root -> right -> left) + maxRob(root -> right -> right));
        }

        int notRobThis = maxRob(root -> left) + maxRob(root -> right);

        int max = robThis > notRobThis ? robThis : notRobThis;

        map[root] = max;

        return max;
    }
};