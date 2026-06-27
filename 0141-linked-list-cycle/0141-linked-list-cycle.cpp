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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!= NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            // now the point where slow and fast collide it is the cycle detected point
            if(slow == fast)
                return true;
        }
        // if we have traversed entire the linked and nothing we got => no cycle detection 
        //=>return false
        return false;
    }
};