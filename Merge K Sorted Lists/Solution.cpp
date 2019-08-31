// 36, 89.89

#include<cstddef>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }

        while (n != 1) {
            int half = n / 2;
            for (int i = 0; i < half; i++) {
                lists[i] = merge(lists[i], lists[i + half]);
            }
            if ((n & 1) != 0) {
                // n is odd
                lists[half] = lists[n - 1];
                n += 1;
            }
            n /= 2;
        }

        return lists[0];
    }

    ListNode* merge(ListNode* p, ListNode* q) {
        ListNode* head = new ListNode(0);

        ListNode* cur = head;

        while (p != NULL && q != NULL) {
            if (p -> val > q -> val) {
                cur -> next = q;
                q = q -> next;
            } else {
                cur -> next = p;
                p = p -> next;
            }
            cur = cur -> next;
        }

        if (p == NULL) {
            cur -> next = q;
        } else {
            cur -> next = p;
        }

        return head -> next;
    }
};