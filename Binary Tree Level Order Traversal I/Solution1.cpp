// 8, 84.86

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        levelOrder(root, result, 0);

        return result;
    }

    void levelOrder(TreeNode* node, vector<vector<int>>& result, int i) {
        if (node == NULL) {
            return;
        }

        if (i >= result.size()) {
            vector<int> level;
            result.push_back(level);
        }

        result[i].push_back(node -> val);

        levelOrder(node -> left, result, i + 1);
        levelOrder(node -> right, result, i + 1);
    }
};