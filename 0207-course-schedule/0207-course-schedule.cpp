class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& nums) 
    {
        vector<int>adj[v];
        for(auto it:nums)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
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
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
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

        // lastly the cycle detection part
        if(count == v)
              return true;// no cycle formed
        else
              return false;      
        
    }
};
// here numcources is basically your vectices
// u--->v in order to perform u task we need to perfprm v first 
