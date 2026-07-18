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
    void deleteNode(ListNode* node) {
        
        // firstly over write the value here
        node->val = node->next->val;
        // then next after overwrite we gonna shift the pointers pointing
        node->next = node->next->next;
        // so here without deelteing from memeory 
        // deleted the node
        // also the order same before and after 
    }
};