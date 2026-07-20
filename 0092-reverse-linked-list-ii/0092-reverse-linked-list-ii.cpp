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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //edge case
        if(head == NULL || head->next == NULL)
                return head;
        //creating of dummy node
        ListNode* dummy = new ListNode(-1);
         dummy->next = head;
        ListNode* prev = dummy;

        // firstly move prev to one position before left
        for(int i =1;i<left;i++)
        {
            prev = prev->next;
        }

        // now hold cur
        ListNode* cur = prev->next;

        //loop (r-l) times
        for(int i =1;i<=abs(right-left);i++)
        {
            ListNode* temp = prev->next;
            prev->next = cur->next;
            cur->next = cur->next->next;//cycle break
            prev->next->next= temp;//cycle break
        }
        return dummy->next;// the head   
    }
};
// its 1 base indexing