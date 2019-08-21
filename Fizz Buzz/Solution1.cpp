// 12, 68.30

#include<vector>
#include<string>

using namespace std;

class Solution1 {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;

        for (int i = 1; i <= n; i++) {
            string temp = "";
            bool flag = true;
            if (i % 3 == 0) {
                temp += "Fizz";
                flag = false;
            }
            if (i % 5 == 0) {
                temp += "Buzz";
                flag = false;
            }
            if (flag) {
                temp += to_string(i);
            }
            result.push_back(temp);
        }

        return result;
    }
};