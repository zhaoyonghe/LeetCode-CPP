// 4, 80.21

#include<string>
#include<vector>

using namespace std;

class Solution1 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vec;
        if(digits.length() == 0){
            return vec;
        }
        vector<string> buttons = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        getCombinations("", digits, 0, vec, buttons);
        return vec;
    }
    
    void getCombinations(string comb, string& digits, int i, vector<string>& vec, vector<string>& buttons){
        if(i == digits.length()){
            vec.push_back(comb);
            return;
        }
        
        string choices = buttons[digits[i] - '2'];
        for(char c: choices){
            comb.push_back(c);
            getCombinations(comb, digits, i + 1, vec, buttons);
            comb.pop_back();
        }
    }
};