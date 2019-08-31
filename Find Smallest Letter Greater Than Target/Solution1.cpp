// 12, 92.09

#include<vector>

using namespace std;

class Solution1 {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target < letters[0] || target >= letters.back()) {
            return letters[0];
        }

        int start = 0;
        int end = letters.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (target < letters[mid]) {
                if (letters[mid - 1] <= target) {
                    return letters[mid];
                }
                // target < letters[mid - 1]
                end = mid - 1;
            } else if (target > letters[mid]) {
                start = mid + 1;
            } else {
                // target == letters[mid]
                int k = mid + 1;
                while (letters[k] == letters[mid]) {
                    k += 1;
                }
                return letters[k];
            }
        }

        return -1;
    }
};