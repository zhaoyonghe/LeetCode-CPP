// 12, 92.21

#include<string>

using namespace std;

class Solution1 {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        string a[numRows];

        for (int i = 0; i < numRows; i++) {
            a[i] = "";
        }

        int cur = 0;
        int step = 1;

        for (int i = 0; i < s.length(); i++) {
            a[cur] += s[i];
            cur += step;
            if (cur == 0) {
                step = 1;
            }
            if (cur == numRows - 1) {
                step = -1;
            }
        }

        string result = "";

        for (int i = 0; i < numRows; i++) {
            result += a[i];
        }

        return result;
    }
};