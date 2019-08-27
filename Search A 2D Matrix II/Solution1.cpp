// 68， 98.35

#include<vector>

using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int i = matrix.size() - 1;
        int j = 0;

        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] < target) {
                j += 1;
            } else if (matrix[i][j] > target) {
                i -= 1;
            } else {
                return true;
            }
        }

        return false;
    }
};