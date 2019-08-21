// 64, 79.98

#include<cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0;
        int lenB = 0;

        ListNode* cur;

        cur = headA;
        while (cur != NULL) {
            lenA += 1;
            cur = cur -> next;
        }

        cur = headB;
        while (cur != NULL) {
            lenB += 1;
            cur = cur -> next;
        }

        ListNode* cur1 = headA;
        ListNode* cur2 = headB;

        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                cur1 = cur1 -> next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                cur2 = cur2 -> next;
            }
        }

        while (cur1 != cur2) {
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }

        return cur1;
    }
};