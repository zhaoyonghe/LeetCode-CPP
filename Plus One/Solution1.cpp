// 4, 88.16

#include<vector>

using namespace std;

class Solution1 {
public:
    vector<int> plusOne(vector<int>& digits) {

        digits[digits.size() - 1] += 1;

        int i = digits.size() - 1;

        while (digits[i] == 10 && i > 0) {
            digits[i] = 0;
            digits[i - 1] += 1;

            i -= 1;
        }

        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};