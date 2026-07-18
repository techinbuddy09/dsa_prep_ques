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
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

       // edge case
        if(head == NULL && head->next == NULL)
        {
            return true;
        }
        //firstly finding the middle of list for odd and even linked list
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // next we gonna reverse the second half
        ListNode* newhead = reverse(slow->next);

        // now lets set two pointers and do the comparison
        ListNode* first = head;
        ListNode* last = newhead;

        while(last!= NULL)
        {
            if(first->val != last->val)
            {
                // firstly reverse
                reverse(last);
                return false;
            }
            // if not so
            first = first->next;
            last = last->next;
        }
        // return false
        //here since no palin detect na
        return true;
    }
};