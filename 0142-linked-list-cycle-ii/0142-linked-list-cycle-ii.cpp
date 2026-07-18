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
        //firstly the detection of cycle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            // now if cycle detected then
            if(slow == fast)
            {
                // we gonna rest the pointer 
                slow = head;
                // and keep the fast pointer at collision point only
                // next traverse till slow !=fast
                while(slow!=fast)
                {
                    // move both the pointer by one step
                    slow = slow->next;
                    fast = fast->next;
                }

                // now here if slow ==  fast yes its the starting point
                if(slow == fast)
                        return slow;
                
            }
        }
        // if nothing works 
        return NULL;
        
    }
};