// 8, 86.51

#include<vector>
#include<stack>
#include<string>

using namespace std;

class Solution1 {
public:
    int calPoints(vector<string>& ops) {
        stack<int> score;

        int sum = 0;

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                sum -= score.top();
                score.pop();
            } else if (ops[i] == "D") {
                sum += (score.top() * 2);
                score.push(score.top() * 2);
            } else if (ops[i] == "+") {
                int num1 = score.top();
                score.pop();
                int num2 = score.top();
                sum += (num1 + num2);
                score.push(num1);
                score.push(num1 + num2);
            } else {
                int num = stoi(ops[i]);
                score.push(num);
                sum += num;
            }
        }

        return sum;
    }
};