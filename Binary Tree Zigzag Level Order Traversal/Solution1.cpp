// 4, 93.83

#include<cstddef>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        levelOrder(root, result, 0);

        for (int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }

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