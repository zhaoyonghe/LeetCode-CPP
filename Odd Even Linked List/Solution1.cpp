// 20, 90.78

#include<cstddef>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        int count = 0;

        ListNode* oddHead = new ListNode(0);
        ListNode* evenHead = new ListNode(0);

        ListNode* odd = oddHead;
        ListNode* even = evenHead;

        ListNode* a = head;

        while (a != NULL) {
            if ((count & 1) == 0) {
                // even
                even -> next = a;
                a = a -> next;
                even = even -> next;
                even -> next = NULL;
            } else {
                // odd
                odd -> next = a;
                a = a -> next;
                odd = odd -> next;
                odd -> next = NULL;
            }
            count += 1;
        }

        even -> next = oddHead -> next;
        return evenHead -> next;

    }
};