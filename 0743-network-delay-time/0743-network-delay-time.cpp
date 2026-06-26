class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //creation of graph
        vector<pair<int,int>>adj[n+1]; // since one base indexing
        for(auto it:times)
        {
            adj[it[0]].push_back({it[2],it[1]});
        }
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n+1,1e9);
        // initial configuration
        pq.push({0,k});
        dis[k] = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            int time = it.first;
            int node = it.second;
            pq.pop();

            // now traverse on the adj
            for(auto it:adj[node])
            {
                int edgetime = it.first;
                int edgenode = it.second;
                if(time+edgetime < dis[edgenode])
                {
                     dis[edgenode]=time+edgetime;
                     pq.push({time+edgetime,edgenode});
                }
            }
        }

        int res = 0;
        for(int i = 1;i<=n;i++)
        {
            if(dis[i] == 1e9)
                 return -1;
            // if not the the max in dis []
            res = max(dis[i],res);    
        }
        return res; 
    }
};