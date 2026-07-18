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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int sum  = 0;
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        // now take a curr pointer and point it to dummy
        ListNode* curr = dummy;
        while(t1!=NULL ||  t2!=NULL)
        {
            // firstly add carry to sum
            sum = carry;
            if(t1)
            {
                sum = sum+t1->val;
            }
            if(t2)
            {
                sum = sum+t2->val;
            }

            ListNode* summy = new ListNode(sum%10);
            carry = sum/10;//update the value of sum too
            curr->next = summy;
            curr = curr->next;

            if(t1)
                t1= t1->next;
            if(t2)
                 t2=t2->next;    
        }

        // next once if any of the list is exhausted so we gonna create carry node and simply add
        if(carry)
        {
            ListNode* carryy = new ListNode(carry);
            curr->next = carryy;
        }

        //and simply return dummy ka next means the sum list 
        return dummy->next;
    }

};