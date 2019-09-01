// 12, 97.09

#include<string>
#include<stack>

using namespace std;

class Solution2 {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1;

        int i = 0;

        st.push(0);

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

                num = st.top() + sign * num;
                st.pop();
                st.push(num);
            } else if (s[i] == '+') {
                sign = 1;
                i += 1;
            } else if (s[i] == '-') {
                sign = -1;
                i += 1;
            } else if (s[i] == '(') {
                st.push(sign);
                st.push(0);
                sign = 1;
                i += 1;
            } else if (s[i] == ')') {
                int num2 = st.top();
                st.pop();

                int sig = st.top();
                st.pop();

                int num1 = st.top();
                st.pop();

                st.push(num1 + sig * num2);
                i += 1;
            } else {
                // s[i] == ' '
                i += 1;
            }
        }

        return st.top();
    }
};