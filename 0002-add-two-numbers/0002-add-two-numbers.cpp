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

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;// basically we have dummy for traversing theek
        int carry = 0;
        while(l1!= NULL || l2!=NULL || carry!= 0)
        {
            int sum = carry ;//add carry theek
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2 = l2->next;
            }

            //next digit se node create and then phir update carry
            int digit = sum%10;
            carry = sum/10;

            ListNode* ewly = new ListNode(digit);
            temp->next = ewly;
            temp = temp->next;
        }

        return dummy->next;
        

    }
};
/*sum = val1 + val2 + carry;
  digit = sum%10;
  carry = sum/10;

  while (l1 != NULL || l2 != NULL || carry != 0)

This last carry != 0 is important.

For:

9 → 9
1

we get:

999? 

Let's use a cleaner example:

l1 = 9
l2 = 1
9 + 1 = 10

Result:

0 → 1

After both lists become NULL, carry is still 1, so we need one final node.

So every iteration:


carry = 0
sum = digit1 + digit2 + carry

Then:

digit = sum % 10
carry = sum / 10

Then:

create node(digit)
move l1
move l2

carry = 0

        ↓
sum = l1 digit + l2 digit + carry
        ↓
digit = sum % 10
        ↓
carry = sum / 10
        ↓
create node(digit)
        ↓
move l1 and l2
        ↓
repeat while:
l1 != NULL || l2 != NULL || carry != 0

*/
