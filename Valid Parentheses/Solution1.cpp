// 0, 100.00

#include <vector>

using namespace std;

class Solution1 {
public:
    bool isValid(string s) {
        vector<char> vec;

        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    vec.push_back(s[i]);
                    break;
                case ')':
                    if (vec.size() == 0 || vec[vec.size() - 1] != '(') {
                        return false;
                    } else {
                        vec.pop_back();
                    }
                    break;
                case ']':
                    if (vec.size() == 0 || vec[vec.size() - 1] != '[') {
                        return false;
                    } else {
                        vec.pop_back();
                    }
                    break;
                case '}':
                    if (vec.size() == 0 || vec[vec.size() - 1] != '{') {
                        return false;
                    } else {
                        vec.pop_back();
                    }
                    break;
            }
        }

        return vec.size() == 0;
    }
};