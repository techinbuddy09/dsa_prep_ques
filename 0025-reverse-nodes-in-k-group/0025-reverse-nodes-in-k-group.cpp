/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        //edge case
        if(head == NULL || k == 1)
             return head;//since only one node na

        // dummy node creation for the case head also need to be reversed
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;//point to the node one before current reverse grp

        //end pointer which points to the last node of current reverse grp

        //step 1 check k nodes availabilty
        while(true) //loop 
        {
        ListNode* end = prev;

        for(int i = 0;i<k;i++)
        {
            end = end->next;

            if(end == NULL) // if end is null
                    return dummy->next;//means dont do any reversal just do the normal reversal

        }   

        // if not we gonna reverse the current group
        ListNode* start = prev->next;
        ListNode* nextgrp = end->next;
        // we need to isloate also the current grp too

        end->next = NULL;

        //next reverse
        ListNode* newhead = reverse(start);

        // once reverse
        //lets do the reconnection
        prev->next = newhead;
        start->next = nextgrp;

        //move prev to the tail node of the curr grp
        prev = start;
        
    }
    return dummy->next;
 }
};
/*previous group → [group being reversed] → next group
so here we do reversal like

first k nodes → reverse
next k nodes → reverse
next k nodes → reverse
...
.......................................................................
For each group we need to know:

groupStart
groupEnd
nextGroup

So conceptually:

prev → [group of k nodes] → nextGroup

After reversal:

prev → [reversed group] → nextGroup

And then move prev to the tail of the reversed group and repeat for the next group.
...............................................................................

Count/check k nodes → reverse k nodes → reconnect → move to next group → repeat.

...................................................................................
Rule of the question:

👉 k nodes available → reverse them
👉 less than k nodes available → leave them as they are
...................................................................................

Check k → prev → start → end → save nextGroup → isolate → reverse(start) → reconnect → prev=start → repeat.
................................................................................

alright so basically what intuition i got here is that ..ques just similar toh reverse ll part 2 theek ..here we gonna have one [prev grp] -> [group of k nodes to be reversed]->[next group].. so basically we have before revsing we nned to whether we have k nodes to reverse ..like if exists we gonna reverse ..and if not we will leave them like  this only ..next so here how we gonna start firstly check nodes..next we will have our one prev pointer..which we will place one node before the reverse group..then next we will have two pointers start and next ..start will basically point to the first node of the reverse group theek ..next we have created one end pointer too theek .joh basically will point to the last node of reversed group theek..now in order to isolate the group we gonna do end->next = null..next we will perform reversal on exactly k nodes wale that is reverse(start).. once group  is reversed .. we gonna use the same logic of reversal theek... now next once its reversed we gonna do the connection part ..where its like ..coneect prev ->next with newhead ..and start->next with nextgroup theek..also toh carry on for other..we will move prev to start ..like start is currently pointing to thelast node of reversed group..theek.. in this way prev point to the one place before next group theek
..............................................................................

Ye loop sirf check kar raha hai ki current position se k nodes available hain ya nahi.

for(int i = 0; i < k; i++)
{
    end = end->next;

    if(end == NULL)
        return dummy->next;
}
Example: k = 3

Agar remaining list hai:

4 → 5 → 6 → 7

end = prev se start hoga.

Loop:

i=0 → end = 4 ✅
i=1 → end = 5 ✅
i=2 → end = 6 ✅

3 nodes mil gaye → reverse karenge.

But agar remaining hai:

4 → 5

Then:

i=0 → end = 4 ✅
i=1 → end = 5 ✅
i=2 → end = NULL ❌

Toh:

if(end == NULL)
    return dummy->next;

Matlab:

"k complete nodes nahi hain, toh yahin stop karo aur list ko current state mein return karo."

So yes, exactly what you said:

k nodes ka complete group nahi hai → reverse nahi karna → remaining nodes ko as-it-is chhod ke return. ✅

......................................................................................
*/