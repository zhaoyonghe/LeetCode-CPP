// 0, 100.00

class Solution1 {
public:
    bool isPerfectSquare(int num) {

        int low = 1;
        int high = num;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long square = (long)mid * (long)mid;
            if (square < num) {
                if (square + 2 * (long)mid + 1 > num) {
                    return false;
                }
                low = mid + 1;
            } else if (square > num) {
                if (square - 2 * (long)mid + 1 < num) {
                    return false;
                }
                high = mid - 1;
            } else {
                // square == num
                return true;
            }
        }
        return false;
    }
};