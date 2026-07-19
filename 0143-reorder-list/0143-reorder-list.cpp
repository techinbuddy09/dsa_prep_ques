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
    void reorderList(ListNode* head) {
        // firtly finding the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // next we have to reverse the second half
        ListNode* rev = reverse(slow);
        ListNode* curr = head;
        while(rev->next!=NULL)
        {
            ListNode* temp1 = curr->next;
            curr->next = rev;
            ListNode* temp2 = rev->next;
            rev->next = temp1;
            curr = temp1;
            rev = temp2;
        }
    }
};