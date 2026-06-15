class Solution {
    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        // first mark  the node visited
        vis[node] = 1;
        //next call dfs on its adjacent neightbours
        for(auto it: adj[node])
        {
            if(!vis[it]) // if not visited then only
            {
                dfs(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        //adjacency matrix to adjacency list conversion
       vector<int>adj[n+1];
       for(int i = 0;i<n;i++)
       {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j] == 1 && i!=j)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
       }
        int count = 0;
        vector<int>vis(n+1,0);
        for(int i = 1;i<=n;i++)
        {
            if(!vis[i])
            {
                //dfs(i,adj,vis);
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};