/*  Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return NULL;
        ListNode *p2=head->next;
        ListNode *p1=head;
        while(p2) {
            if(p1->val!=p2->val) {
                p1->next = p2;
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        p1->next = NULL;
        return head;
    }
};
