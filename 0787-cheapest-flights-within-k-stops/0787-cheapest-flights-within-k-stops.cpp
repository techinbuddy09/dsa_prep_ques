class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // creation of graph
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dis(n,1e9);
        //initial configuration
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty())
        {
            auto it = q.front();//follows the principle fifo
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            //if suppose stops > k(at most wale se toh just continue nothing else)
            if(stop>k) continue;
            // else we gonna traverse on the adjacent one
            for(auto it:adj[node])
            {
                int edgenode = it.first;
                int edgewt = it.second;

                //now the dj check for the min distance updation also within the range of the k stops over here
                if(cost+edgewt < dis[edgenode] && stop<=k) // stop<=k means within range eak extar toh last destination time 
                {
                    // if so update it 
                    dis[edgenode] = cost+edgewt;
                    q.push({stop+1,{edgenode,cost+edgewt}});
                }
            }
        }

        // now check if destination still not reachable return -1
        if(dis[dst] == 1e9)
                return -1;
        // if not return 
        return dis[dst];// storing the min distance withing the range of k stops        
        
    }
};
// basically here in this ques the normal dj algo it fails
// we will be using the normal queue over here not any pq here like we are taking stops as priority and minimum
