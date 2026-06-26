class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // create graph
        vector<pair<long,long>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long>dis(n,LONG_MAX);
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>>pq;
        vector<long>ways(n,0);

        //initial configuration
        dis[0] = 0;
        ways[0] = 1;
        int mod = int(1e9+7);//since the return type is int type na
        pq.push({0,0});

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long d = it.first;
            long long node = it.second;
           //pq.pop();

            // now traverse on the adjacent
            for(auto it:adj[node])
            {
                long long  edgenode = it.first;
                long long  edgewt = it.second;

                if(d+edgewt < dis[edgenode])
                {
                    dis[edgenode]=d+edgewt;
                    pq.push({d+edgewt,edgenode});
                    // update the ways array too
                    ways[edgenode]= ways[node];
                }
                //now case iof suppose same node then
               else  if(d+edgewt  == dis[edgenode])
               {
                // update the ways array by retracing the entire path
                    ways[edgenode]=(ways[node]+ways[edgenode])%mod;// for modulo
               }
            }
        }
        // now returning n-1 in the distance array because it willl  be holding the the number of ways with shortest time
        return ways[n-1]%mod;
    }
};