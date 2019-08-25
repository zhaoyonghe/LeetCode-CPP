// 0, 100.00

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            bool isBV = isBadVersion(mid);
            if (isBV) {
                if (mid >= 2 && isBadVersion(mid - 1)) {
                    high = mid - 1;
                } else {
                    return mid;
                }
            } else {
                low = mid + 1;
            }
        }
        return 0;
    }
};