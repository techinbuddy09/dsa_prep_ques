class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& nums) {
        vector<int>adj[v];
        for(auto it:nums)
        {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int>indeg(v);
        for(int i = 0;i<v;i++)
        {
            for(auto it:adj[i])
            {
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i = 0;i<v;i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        int count =0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            topo.push_back(node);
            //traverse on the adjacents
            for(auto it:adj[node])
            {
                indeg[it]--;
                if(indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(count == v)
             return topo;
        else
              return {};     
        
        
    }
};