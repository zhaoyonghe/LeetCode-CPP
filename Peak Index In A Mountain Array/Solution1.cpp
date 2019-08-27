// 4, 76.45

#include<cstddef>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast != NULL && fast -> next != NULL) {
			fast = fast -> next -> next;
			slow = slow -> next;
		}

		return slow;
	}
};