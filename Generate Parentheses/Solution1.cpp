// 4, 97.66

#include<string>
#include<vector>

using namespace std;

class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        generateParenthesis("", vec, 0, 0, n);
        return vec;
    }
    
    void generateParenthesis(string s, vector<string>& vec, int left, int right, int n) {
        if(left == n && right == n){
            vec.push_back(s);
            return;
        }
        
        if(left < n){
            s.push_back('(');
            generateParenthesis(s, vec, left + 1, right, n);
            s.pop_back();
        }
        
        if(left > right){
            s.push_back(')');
            generateParenthesis(s, vec, left, right + 1, n);
            s.pop_back();   
        }

    }
};