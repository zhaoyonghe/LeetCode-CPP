// 12, 93.35

#include<cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }

        ListNode* a = head;

        int count = 0;
        while (a != NULL) {
            a = a -> next;
            count += 1;
        }

        a = head;
        ListNode* b = head;

        while (b -> next != NULL && b -> next -> next != NULL) {
            a = a -> next;
            b = b -> next -> next;
        }

        if ((count & 1) == 0) {
            a = a -> next;
        }

        b = head;
        ListNode* c = NULL;

        while (b != a) {
            ListNode* temp = b -> next;
            b -> next = c;
            c = b;
            b = temp;
        }

        if ((count & 1) != 0) {
            a = a -> next;
        }

        b = c;

        while (a != NULL && b != NULL) {
            if (a -> val != b -> val) {
                return false;
            }
            a = a -> next;
            b = b -> next;
        }

        return true;
    }
};