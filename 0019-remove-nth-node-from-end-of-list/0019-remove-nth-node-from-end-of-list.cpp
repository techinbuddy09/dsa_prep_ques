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
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow  =  dummy;
        ListNode* fast = dummy ;

        //lets move fast by steps to create n gaps between the two pointers 
        for(int i = 0 ;i<n; i++)
        {
            fast = fast->next;
        }

        //next lets move the pointers till one reach null
        while(fast->next!=NULL)
        {
            slow  = slow->next;
            fast = fast->next;
        }

        //next lets do chnages of the links over here theek
        slow->next = slow->next->next;


        // next return dummy->next ..because it points to head na
        return dummy->next;

    }
};
/*we have to basically remember Keep slow and fast n positions apart. Move both until fast->next == NULL. Now slow is exactly one node before the target. Skip slow->next.

1. Dummy banao
   ↓
   dummy->next = head

2. slow = dummy
   fast = dummy

3. fast ko n steps aage move karo
   → n ka gap create

4. slow + fast dono ko move karo
   → jab tak fast->next == NULL

5. Ab slow target se ONE NODE pehle hai

6. Target ko skip karo
   → slow->next = slow->next->next

7. dummy->next return karo


the basic reason for creating a dummy node here is that if suppose the target which we have to delete is the head only toh ..toh agar usse hi delete kardiya how we will  return our list .. thats the reason we have created a dummy one here an artifically node which points head .. in this way we can remove our head nodes like other linked lists
*/
