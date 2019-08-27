// 4, 83.76

#include<string>
#include<stack>

using namespace std;

class Solution1 {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> a;
        stack<char> b;

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '#') {
                if (!a.empty()) {
                    a.pop();
                }
            } else {
                a.push(S[i]);
            }
        }

        for (int i = 0; i < T.length(); i++) {
            if (T[i] == '#') {
                if (!b.empty()) {
                    b.pop();
                }
            } else {
                b.push(T[i]);
            }
        }

        if (a.size() != b.size()) {
            return false;
        }

        while (!a.empty()) {
            if (a.top() != b.top()) {
                return false;
            }
            a.pop();
            b.pop();
        }

        return true;
    }
};