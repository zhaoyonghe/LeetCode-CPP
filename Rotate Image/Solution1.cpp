// 4, 96.96

#include<vector>

using namespace std;

class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int a = (n + 1) / 2;
        int b = n / 2;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};