/* Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid. */
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode *pre = &dummyNode, *lat = &dummyNode;
        for(int i=0;i<n&&pre;i++) {
            pre = pre->next;
        }
        if(!pre || n==0) return dummyNode.next;
        while(pre->next) {
            lat = lat->next;
            pre = pre->next;
        }
        lat->next=lat->next->next;    
        return dummyNode.next;
    }
};
