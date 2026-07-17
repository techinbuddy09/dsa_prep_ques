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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        // firstly we gonna move fast by the n steps
        for(int i = 0 ;i<n;i++)
        {
            fast = fast->next;
        }

        //suppose if ourhead is the node we have to delete
        if(fast == NULL)
        {
            ListNode* delnode = head;
            head = head->next;
            delete(delnode);
            return head;
        }

        // if not we gonna traverse
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete(del);
        return head;
        
    }
};