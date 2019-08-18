// 4, 97.90

#include<cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a = new ListNode(0);
        a -> next = head;

        ListNode* fast = a;
        ListNode* slow = a;

        for (int i = 0; i < n; i++) {
            fast = fast -> next;
        }

        while (fast -> next != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }

        slow -> next = slow -> next -> next;

        return a -> next;
    }
};