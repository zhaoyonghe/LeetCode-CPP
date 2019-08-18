// 8, 97.97

#include <cstddef>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);

        ListNode* cur = head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1 -> val < l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            } else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }

        cur -> next = l1 == nullptr ? l2 : l1;

        return head -> next;
    }
};