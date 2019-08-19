// 56, 88.82

#include<vector>
#include<unordered_map>

using namespace std;

class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, int> map;

        int index = 0;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            auto it = map.find(temp);
            if (it == map.end()) {
                // new anagram

                vector<string> a;
                a.push_back(strs[i]);
                result.push_back(a);

                map[temp] = index;
                index += 1;
            } else {
                result[it -> second].push_back(strs[i]);
            }
        }

        return result;
    }
};