/* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. */
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
    void reorderList(ListNode *head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode *pre = head, *lat = head, *p = head, *mid;
        while(pre->next && pre->next->next) {
            pre = pre->next->next;
            lat = lat->next;
        }
        mid = lat->next;
        pre = mid;
        lat = mid->next;
        while(lat) {
            ListNode *tmp = lat->next;
            lat->next = pre;
            pre = lat;
            lat = tmp;
        }
        mid->next = NULL;
        while(p && pre && (p!=pre)) {
            ListNode *tmp1 = p->next;
            ListNode *tmp2 = pre->next;
            p->next = pre;
            pre->next = tmp1;
            p = tmp1;
            pre = tmp2;
        }
        p->next = NULL;
    }
};
