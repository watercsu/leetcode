/* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space? */
/* http://blog.csdn.net/kenden23/article/details/13871699 
设：链表头是X，环的第一个节点是Y，slow和fast第一次的交点是Z。各段的长度分别是a,b,c，如图所示。环的长度是L。slow和fast的速度分别是qs,qf。
第一次相遇时slow走过的距离：a+b，fast走过的距离：a+b+c+b。

因为fast的速度是slow的两倍，所以fast走的距离是slow的两倍，有 2(a+b) = a+b+c+b，可以得到a=c（这个结论很重要！）。

如果圈很小，而a很长，那么b的长度就会是绕圈几周了，但是结果也是一样成立的。
既然有人说上面没能证明a很长，而圈很小的时候的情况，那么我就增加几句普通情况下的证明吧，就是不管圈的大小去证明吧：
1.  假设圈的周长L
2. 那么相遇的时候slow走：a + b,而fast走：a + b + n*L，（n代表fast走了多少圈）
3. fast走路的路程是slow的两倍，那么2(a+b) = a + b + n*L，得到a = n*L - b
4 从相遇点的时候开始，放一个指针从开始点走起，另一个指针继续走，而且这时走的速度都是一样的，那么当一个指针从开始点X走到循环圈点Y的时候，走了a路程，而另一个指针走的路程是n*L-b，那么两者的路程是一样的，相遇点必然是Y。
从而定理得到证明，而不管这个圈的大小。
这样的证明够严密了，哪里用得着那么啰嗦，什么圈大圈小的都可以不用管。圈大的时候，不过是n == 1的特殊情况。*/
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool isBegin = true;
        while(fast && fast->next && (isBegin||slow!=fast)) {
            isBegin = false;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(!fast || !fast->next) return NULL;
        slow = head;
        while(fast!=slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
