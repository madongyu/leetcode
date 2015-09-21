#include <iostream>
using std::cout;
using std::endl;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
存储反序
100 => [0,0,1]

链表大数相加
[0] + [0] => [0]
[5] + [5] => [0,1]
[5] + [0,3] = > [5,3]
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* result = NULL;
	ListNode** cur = &result;

	int upgrade = 0;
	while (l1 != NULL && l2 != NULL)
	{
		int re = l1->val + l2->val + upgrade;
		upgrade = re / 10;
		l1 = l1->next;
		l2 = l2->next;
		(*cur) = new ListNode(re % 10);
		cur = &((*cur)->next);
	}
	if (l1 != NULL || l2 != NULL) {
		ListNode* remind = l1 == NULL ? l2 : l1;
		while (remind != NULL)
		{
			int re = remind->val + upgrade;
			upgrade = re / 10;
			remind = remind->next;
			(*cur) = new ListNode(re % 10);
			cur = &((*cur)->next);
		}
	}
	else {
		if (upgrade) {
			(*cur) = new ListNode(1);
			cur = &((*cur)->next);
		}
	}
	return result;
}

void convert(ListNode **head, int *a, int n) {
	for (int i = 0; i < n; i++) {
		(*head) = new ListNode(a[i]);
		head = &((*head)->next);
	}
}

void print(ListNode *head) {
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}