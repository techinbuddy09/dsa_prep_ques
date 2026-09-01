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
        ListNode* slow = head;
        ListNode* fast = head;
        // firstly cycle detection
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow ->next;
            fast = fast->next->next;

            if(slow == fast) // if point of collsion found toh rest it
            {
                slow = head;

                // next move both by 1-1 step only
                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                    if(slow == fast) //means entrance found here
                    {
                        return slow;
                    }
            }
        }
        // if nothing works in that case return null
        return NULL;
        
    }
};
/* 
   alright so the mofification which we have in this ques is that in this ques we have to return the starting point of the cycle .. if cycle exists

1️⃣ Slow + Fast → find collision

2️⃣ Collision found

3️⃣ Move slow back to head

4️⃣ Move both slow and fast ONE step at a time

5️⃣ Where they meet again = cycle starting node

=> as a notes we can add it here

imp intuition -: The reason is that after the first collision, the distance from head to the cycle start is equal to the distance from the collision point around the cycle to the cycle start

That's why putting one pointer at head and moving both one step makes them meet exactly at the cycle entrance.
*/