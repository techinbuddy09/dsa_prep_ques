class Solution {
    bool dfs(int node,int r_c,vector<int>&color,vector<vector<int>>&graph)
    {
        // sabse phele mark as visited
        color[node] = r_c;
        //next df call
        for(auto it:graph[node])
        {
            if(color[it] == -1)
            { 
                // we will be checking the neighbour and the dfs call will on the neighbour
                if(dfs(it,!r_c,color,graph) == false)
                {
                    return false;// if any dfs call is false so return false
                }
            }
            else if(color[it] == r_c)
            {
                return false;// like the adjacent node colors are same
            }
        }
        // if nothing reached end so  true
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // see for the bipartite graph we dont need to create the adjacency list
        int n = graph.size();
        vector<int>color(n,-1);
        //next we will traverse on the multiple components
        for(int i = 0;i<n;i++)
        {
            if(color[i] == -1)
            {
                // means no color assigned and not visited toh do a dfs call
               if(dfs(i,0,color,graph) == false)
               {
                    return false;//if any of the dfs call is false sop return false
               }
            }
        }
        return true;// if nothing and reaches end
    }
};