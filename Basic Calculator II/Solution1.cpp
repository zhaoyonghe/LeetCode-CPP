// 8, 98.58

#include<string>
#include<stack>

using namespace std;

class Solution1 {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';

        int i = 0;

        while (i < s.length()) {
            if ('0' <= s[i] && s[i] <= '9') {
                // is digit
                // construct the number
                int num = 0;
                while (i < s.length() && '0' <= s[i] && s[i] <= '9') {
                    num *= 10;
                    num += (s[i] - '0');
                    i += 1;
                }
                switch (sign) {
                    case '-':
                        num = -num;
                        break;
                    case '*':
                        num *= st.top();
                        st.pop();
                        break;
                    case '/':
                        num = st.top() / num;
                        st.pop();
                        break;
                }
                st.push(num);
            } else if (s[i] == ' ') {
                i += 1;
            } else {
                sign = s[i];
                i += 1;
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};