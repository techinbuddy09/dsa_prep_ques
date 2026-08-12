class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        // firstly the frquency map
        unordered_map<int,int>mp;
        for(int no:nums)
        {
            mp[no]++;
        }

        //next push in min heap and pop the small omes
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //lets iterate in the map and push in pq
        for(auto it:mp)
        {
            pq.push({it.second,it.first});//we gonna push {freq,element}

            // next also we have to maintain the size of the min heap that it should be of size k na
             if(pq.size() > k)
             {
                pq.pop();
             }
        }

        // next now by this time our priority queue holding the top k most frequent elements here

        // lets push them in our vector and return it
        vector<int>res;

        //push elements in the vector till the pq not empty
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;

    }
};
// we have to basically return the k most frequent elements over here
//means 2 most frequent elements
// as the question states here na top k frequent elements na means top 2 most frequent elements na
// so basically here jin doh elements ki frequency top 2 frequents mein aye
