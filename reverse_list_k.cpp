#include "leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// leetcode 25
 ListNode* reverseList(ListNode* head) {
 	if (!head || !(head->next))
 		return head;
 	ListNode* reverseHead = reverseList(head->next);
 	head->next->next = head;
 	head->next = 0;
 	return reverseHead;
 }

 ListNode* reverseListK(ListNode* head, int k) {
 	if (!head || !(head->next))
 		return head;
 	ListNode* tail = head, *nextHead = head;
 	int kk = k;
 	while ((k--) > 0 && nextHead) {
 		tail = nextHead;
 		nextHead = nextHead->next;
 	}
 	if (!nextHead)
 		return (k == -1)?reverseList(head):head;
 	tail->next = 0;
 	ListNode* reverseHead = reverseList(head);
 	head->next = reverseListK(nextHead, kk);
 	return reverseHead;
 }