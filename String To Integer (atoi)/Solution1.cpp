// 4, 93.40

#include<string>
#include<climits>

using namespace std;

class Solution1 {
public:
    int myAtoi(string str) {
        int i = 0;

        // ignore the whitespaces
        while (str[i] == ' ') {
            i += 1;
        }

        // now, str[i] is the first character that is not a whitespace
        // if it is not '-' and '+' and digit
        if (str[i] != '-' && str[i] != '+' && str[i] < '0' && str[i] > '9') {
            return 0;
        }

        bool isMinus = false;
        // if it is '-' or '+'
        if (str[i] == '-' || str[i] == '+') {
            if (i + 1 < str.length() && str[i + 1] >= '0' && str[i + 1] <= '9') {
                isMinus = (str[i] == '-');
                i += 1;
            } else {
                // if there is no digit behind '-' or '+'
                return 0;
            }
        }

        int count = 0;
        long num = 0;

        while (i < str.length() && str[i] >= '0' && str[i] <= '9' && count <= 11) {
            num *= 10;
            num += str[i] - '0';

            if (num != 0) {
                count += 1;
            }

            i += 1;
        }

        if (isMinus) {
            num = -num;
            if (num < (long)INT_MIN) {
                return INT_MIN;
            } else {
                return (int)num;
            }
        } else {
            if (num > (long)INT_MAX) {
                return INT_MAX;
            } else {
                return (int)num;
            }
        }

    }
};