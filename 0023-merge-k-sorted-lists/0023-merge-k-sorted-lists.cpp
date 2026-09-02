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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        ListNode*dummy = new ListNode(-1);
        ListNode* tail = dummy;// for traversing 
        //next lets firstly iterate in each list and push the current element and node 
        for( auto list:lists)
        {
            //if value there then only add
            if(list!=NULL)
            {
                pq.push({list->val,list});
            }
        }
        //lets pop and connect and update
        while(!pq.empty())
        {
            auto[val,node] = pq.top();
            pq.pop();

            //next do connection 
            tail->next = node;
            tail = tail->next;//move the pointer

            // also need to update too
            if(node->next!=NULL)
            {
                pq.push({node->next->val,node->next});
            }
        }

        return dummy->next;

        
    }
};