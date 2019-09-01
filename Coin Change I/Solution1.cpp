// 60, 87.71

#include<vector>
#include<climits>

using namespace std;

class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> vec(amount + 1, INT_MAX);
        vec[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && vec[i - coin] != INT_MAX && vec[i] > vec[i - coin] + 1) {
                    vec[i] = vec[i - coin] + 1;
                }
            }
        }

        return vec.back() == INT_MAX ? -1 : vec.back();
    }
};