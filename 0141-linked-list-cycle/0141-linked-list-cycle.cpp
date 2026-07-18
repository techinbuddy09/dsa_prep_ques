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
    bool hasCycle(ListNode *head) {
        //here we gonna use  the approach of slow and fast   
        ListNode * slow = head;
        ListNode* fast = head;
        //now the loop for interation edge case handling
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            // if s ==  f means node d
            if(slow == fast)
                    return  true;
        }        
        // if nothing found
        return false;
    }
};