class Solution {
    bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<int>&rec,vector<vector<int>>& graph)
    {
        //initial configurations
        vis[node] =1;
        pathvis[node] = 1;
        rec[node] = 0;
        // next traverse on the adjacents
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathvis,rec,graph) == true)
                {
                    rec[it] = 0;
                    return true;// like cycle found
                }
            }
            else if(pathvis[it])
            {
                rec[it]=0;
                return true;// cycle found since both vis+pathvis
            }
        }
        // if nothing so simply backtrack and make the node not pathvisited
        rec[node] = 1;
        pathvis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>safe_nodes;
        vector<int>rec(n,0);
        //iterate on the multiple components
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,pathvis,rec,graph);// we wont return here true on one dfs call like suppose on one dfs call got cycle so we cant return true we need to check for all the multiple nodes
            }
        }
        //  next reiterate
        for(int i = 0;i<n;i++)
        {
            if(rec[i] == 1)
            {
                safe_nodes.push_back(i);
            }
        }
        return safe_nodes;
    }
};