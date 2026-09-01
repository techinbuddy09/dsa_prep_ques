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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // WE GONNA SET THE TWO POINTERS AT THETWO LIST HERE THEEK
    ListNode* l1 = headA;
    ListNode* l2 = headB;

    //iterate till both not equal
    while(l1!=l2)
    {
        if(l1 == NULL)
            l1 = headB;
        else
            l1 = l1->next;

         if(l2 == NULL)
            l2 = headA;
         else
            l2 = l2->next;          
    }
    return l1;
        
    }
};
/* we have to return actual node which is the intersection of two linked list instead of value

The two lists can have different lengths.

For example:

A: 1 → 2 → 3 → 7 → 8
B:      4 → 5 → 7 → 8

If we simply start:

p1 = headA
p2 = headB

they won't reach the common part at the same time.

So we need to somehow cancel out the length difference.

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
The pointer-switching trick

We use two pointers:

p1 = headA;
p2 = headB;

Then:

p1 moves through A
p2 moves through B

When p1 reaches NULL, put it at headB.

When p2 reaches NULL, put it at headA.

So:

if (p1 == NULL)
    p1 = headB;

if (p2 == NULL)
    p2 = headA;
Why does this work?

Because each pointer eventually travels:

A + B

So both pointers travel the same total distance.

🔑 The complete intuition

Two pointers traverse both lists. When one reaches NULL, switch it to the other list's head. This makes both pointers travel the same total distance. Therefore, if an intersection exists, they meet exactly at the intersection node.

And if there is no intersection, they'll both eventually become NULL.

So the stopping condition is simply:

while (p1 != p2)

At the end:

return p1;

because p1 and p2 are either:

the intersection node, or
both NULL.

*/