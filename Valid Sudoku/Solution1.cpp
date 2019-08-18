// 16, 88.79

#include <vector>

using namespace std;

class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row by row
        for (int i = 0; i < 9; i++) {
            int a[9] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (a[board[i][j] - '1'] == 0) {
                        a[board[i][j] - '1'] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }

        // col by col
        for (int j = 0; j < 9; j++) {
            int a[9] = {0};
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (a[board[i][j] - '1'] == 0) {
                        a[board[i][j] - '1'] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }

        // block by block
        // select block
        for (int m = 0; m < 9; m += 3) {
            for (int n = 0; n < 9; n += 3) {
                int a[9] = {0};
                // select position
                for (int i = 0; i < 3; i++) {
                    int row = m + i;
                    for (int j = 0; j < 3; j++) {
                        int col = n + j;
                        if (board[row][col] != '.') {
                            if (a[board[row][col] - '1'] == 0) {
                                a[board[row][col] - '1'] = 1;
                            } else {
                                return false;
                            }
                        }
                    }
                }

            }
        }

        return true;
    }
};