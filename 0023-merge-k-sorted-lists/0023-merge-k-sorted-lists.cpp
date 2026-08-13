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
        
        //here in this question we gonna maintain min heap as we want to mege the k sorted linked lists in the sorted format
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        //next lets iterate on each linked list push current node val of each list in the pq ...means the first value of each list...first value always sorted

        for(auto list:lists)
        {
            if(list!=NULL) // wahi basicaaly our condition states that if the list not empty toh push the list ki val aur list ...and similary traverson on the other k list over here theek
            {
                pq.push({list->val,list});
            }   
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;// basically using this list for traversing 

        // now lets pop  from pq [node->val,node]
        while(!pq.empty())
        {
            auto[val,node] = pq.top();
            pq.pop();

            //lets add the ans first
            tail->next = node;
            // move the pointer 
            tail = tail->next;

            //next if the node ka exists the push the next value of the linked list into the pq
            if(node->next!=NULL)
            {
                pq.push({node->next->val,node->next});
            }
        }
   return dummy->next;

    }
};

