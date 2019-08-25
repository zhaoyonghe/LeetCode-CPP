// 20, 96.05

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }

        int mid = (start + end) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root -> left = buildTree(nums, start, mid - 1);
        root -> right = buildTree(nums, mid + 1, end);

        return root;
    }
};