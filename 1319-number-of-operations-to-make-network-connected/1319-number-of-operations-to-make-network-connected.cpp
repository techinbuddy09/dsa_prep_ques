class djs
{
    vector<int>parent,size;
    public:
            djs(int n)
            {
                parent.resize(n+1);
                size.resize(n+1);
                for(int i = 0;i<n;i++)
                {
                    parent[i] = i;
                }
                for(int i = 0;i<n;i++)
                {
                    size[i] = 1;
                }
            }

            int findupar(int node)
            {
                if(node ==  parent[node])
                {
                    return node;
                }
                return parent[node] = findupar(parent[node]);
            }

            void sizee(int u , int v)
            {
                int ulp_u = findupar(u);
                int ulp_v = findupar(v);

                if(ulp_u == ulp_v) return ;
                else if (size[ulp_u] < size[ulp_v])
                {
                    parent[ulp_u] = ulp_v;
                    size[ulp_v]+=size[ulp_u];
                }
                else
                {
                    parent[ulp_v] = ulp_u;
                    size[ulp_u]+=size[ulp_v];
                }
            }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        djs ds(n);

        int count_extra_edges = 0;
        //lets iterate in the graph
        for(auto it: connections)
        {
            int u = it[0];
            int v = it[1];

            // now lets check if ultimate parents 
            if(ds.findupar(u) == ds.findupar(v))
            {
                count_extra_edges++;// increse the count of the extra edges
            }
            else
            {
                // if not connect them by union by size
                ds.sizee(u,v);
            }
        }

        // next lets count the no of components
        int nc = 0;
        for(int  i = 0;i<=n;i++)
        {
            // if node is the ultimate parent of itself
            if(ds.findupar(i) == i)
            {
                nc++;
            }
        }

        // next lets calculate the minimum number of edges
        int ans = abs(nc-1);

        // if extra_eges>= nc then we connect by min edges
        if(count_extra_edges  >= ans)
        {
            return ans;
        }
        else
            return -1;
    }
};