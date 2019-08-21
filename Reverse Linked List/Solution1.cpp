// 12, 84.54

#include <cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* cur1 = head;
        ListNode* cur2 = head -> next;

        ListNode* newHead = NULL;

        while (cur2 != NULL) {
            cur1 -> next = newHead;
            newHead = cur1;
            cur1 = cur2;
            cur2 = cur2 -> next;
        }

        cur1 -> next = newHead;

        return cur1;
    }
};