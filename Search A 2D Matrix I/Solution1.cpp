// 12, 76.94

#include<vector>

using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0;
        int end = m - 1;

        int i = -1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (matrix[mid][0] < target) {
                if (mid == m - 1 || target < matrix[mid + 1][0]) {
                    i = mid;
                    break;
                } else {
                    start = mid + 1;
                }
            } else if (matrix[mid][0] > target) {
                end = mid - 1;
            } else {
                return true;
            }
        }

        if (i == -1) {
            return false;
        }

        start = 0;
        end = n - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (matrix[i][mid] < target) {
                start = mid + 1;
            } else if (matrix[i][mid] > target) {
                end = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};