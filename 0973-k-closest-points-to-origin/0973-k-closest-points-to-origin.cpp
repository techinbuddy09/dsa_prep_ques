class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        //max heap
        priority_queue<pair<int,pair<int,int>>>pq;
        //lets iterate
        for(int i = 0;i<n;i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int dis = x*x + y*y;
            pq.push({dis,{x,y}});

            // now lets see whether it exceeds size then pop
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>>ans;

        //lets traverse and push in vector
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();// we also need to pop from pq
           // here we have pair of inside pair type na 
           // toh dis =  it.second.first
           // points = it.second.second
            ans.push_back({it.second.first,it.second.second});
        }
        
        return ans;
    }
};
