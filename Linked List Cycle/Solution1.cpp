// 4, 99.98

#include<cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    bool hasCycle(ListNode* head) {
        ListNode* a = head;
        ListNode* b = head;

        while (b != NULL && b -> next != NULL) {
            a = a -> next;
            b = b -> next -> next;

            if (a == b) {
                return true;
            }
        }

        return false;
    }
};