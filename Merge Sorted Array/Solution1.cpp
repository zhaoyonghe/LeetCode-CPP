// 0, 100

#include<vector>

using namespace std;

class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1;
        int q = n - 1;
        int i = m + n - 1;

        while (p >= 0 || q >= 0) {
            if (p < 0) {
                nums1[i] = nums2[q];
                q -= 1;
                i -= 1;
                continue;
            }

            if (q < 0) {
                nums1[i] = nums1[p];
                p -= 1;
                i -= 1;
                continue;
            }

            if (nums1[p] > nums2[q]) {
                nums1[i] = nums1[p];
                p -= 1;
            } else {
                nums1[i] = nums2[q];
                q -= 1;
            }

            i -= 1;
        }
    }
};