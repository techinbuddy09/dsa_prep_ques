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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        //edge case
        if(head == NULL || k == 1)
        {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = dummy ;
        ListNode* nex = dummy;
        int count = 0;
        // counting the number of nodes over here
        while(cur->next!=NULL)
        {
            count++;
            cur = cur->next;

        }   

        // if the count within the valid range toh do pointer changements

        while(count>=k)
        {
            // for new grep separation
            cur = prev->next;
            nex = cur->next;


            // now iterate k-1 operations on each grp
            
            for(int i = 1;i<k;i++)
            {
                cur->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = cur->next;
            }

            // now update 
            prev = cur;
            count = count-k;
        }    
        return dummy->next; 
    }
};