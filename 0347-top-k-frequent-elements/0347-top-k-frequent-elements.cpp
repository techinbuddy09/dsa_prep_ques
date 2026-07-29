class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // sabse phele we will make the frequency map
        unordered_map<int,int>mp;
        for(int no:nums)
        {
            mp[no]++;//done with the frequency map
        }

        // next lets make the min heap of pair type
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //lets iterate in the frequency map and push in pq
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
            if(pq.size() > k)
            {
                pq.pop();//if the size it exceeeds the the k size we need to pop
            }
        }

        // next we gonna reiterate and push the elements in the vector till the pq its not empty
        vector<int>ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

        //t.c 
        //traversing in the hashmap => O(n)
        // for the heap operations => O(mlogk)
        
    }
};
