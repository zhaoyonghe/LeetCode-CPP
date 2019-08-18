// 28, 94.11

#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);

        ListNode* c = head;

        ListNode* a = l1;
        ListNode* b = l2;

        int carry = 0;

        while (a != nullptr || b != nullptr) {
            int aVal = (a == nullptr ? 0 : a -> val);
            int bVal = (b == nullptr ? 0 : b -> val);

            int sum = aVal + bVal + carry;

            carry = sum / 10;
            sum = sum % 10;

            c -> next = new ListNode(sum);

            c = c -> next;

            if (a != nullptr) {
                a = a -> next;
            }
            if (b != nullptr) {
                b = b -> next;
            }
        }

        if (carry == 1) {
            c -> next = new ListNode(1);
        }

        return head -> next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(9);

    Solution1 solution1;

    ListNode* result = solution1.addTwoNumbers(a, b);

    std::cout << result -> val;
    return 0;
}