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
            temp->next =  prev;
            prev =  temp;
            temp =  front;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        // the edge case 
        if( head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // next reverse the second half
        ListNode* newhead = reverse(slow->next);

        //next lets take two pointers to compare
        ListNode* first = head;
        ListNode* last = newhead;

        while(last!=NULL)
        {
            if(first->val != last->val)
            {
                reverse(slow->next);
                return false;
            }

            // if not keep on moving
            first = first->next;
            last =  last->next;
        }
        // if able to traverse end tak 
        return true;
    }
};
/* a linked list is considered palindromic if it reads same from both the ends
Think about what we need to compare:

1 → 2 → 3 → 2 → 1

We need:

first half:   1 → 2
second half:  2 → 1

If we could somehow reverse the second half, we'd get:

First half:   1 → 2
Second half:  1 → 2

Then we can simply compare them node by node.



Find middle
     ↓
Reverse second half
     ↓
Compare first half & reversed second half
     ↓
all same → palindrome
otherwise → not palindrome


// we are  trying to do in such a way that we exclude the middle and reverse only th second half hi bass

Middle LL: find the middle.
Palindrome LL: find the middle in a way that lets us start reversing the second half from slow->next

isilya we kept our condition as fast->next!=NULL && fast->next->next!=NULL

*/