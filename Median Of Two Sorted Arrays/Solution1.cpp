// 16, 97.63

#include<vector>
#include<climits>

using namespace std;

class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();

        if (a > b) {
            return findMedianSortedArrays(nums2, nums1);
        }

        if (a == 0) {
            return (b & 1) == 0 ? ((double)nums2[b / 2 - 1] + (double)nums2[b / 2]) / 2 : (double)nums2[b / 2];
        }

        int numOnTheLeft = (a + b) / 2;

        int low = 0;
        int high = a;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = numOnTheLeft - i;

            int nums1Left = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums1Right = (i == a ? INT_MAX : nums1[i]);
            int nums2Left = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums2Right = (j == b ? INT_MAX : nums2[j]);

            if (nums1Right < nums2Left) {
                low = i + 1;
            } else if (nums2Right < nums1Left) {
                high = i - 1;
            } else {
                // nums1Right >= nums2Left && nums2Right >= nums1Left
                if (((a + b) & 1) == 0) {
                    // even
                    return (double)(max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2;
                } else {
                    // odd
                    return (double)min(nums1Right, nums2Right);
                }
            }
        }

        return 0;
    }
};