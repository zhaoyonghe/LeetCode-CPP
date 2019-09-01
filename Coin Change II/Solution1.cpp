// 8, 94.82

#include<vector>

using namespace std;

class Solution1 {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> vec(amount + 1, 0);
        vec[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                vec[i] += vec[i - coin];
            }
        }

        return vec.back();
    }
};