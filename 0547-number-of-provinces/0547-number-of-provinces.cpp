class djs
{
    //firstly the parent and size array
    vector<int>parent,size;
    public:
            djs(int n) //constructor
            {
                parent.resize(n+1);
                size.resize(n+1);
                //now lets iterate and initialize the values
                for(int i = 0;i<=n;i++)
                {
                    parent[i] = i;
                }

                // size array
                for(int i =0;i<=n;i++)
                {
                    size[i] = 1;
                }
            }

            int findupar(int node) //
            {
                if(node == parent[node])
                        return node;
                return parent[node] = findupar(parent[node]);        
            }

            void union_bysize(int u , int v)
            {
                // firstly finding the ultimate parents
                int ulp_u = findupar(u);
                int ulp_v = findupar(v);
                
                if(ulp_u == ulp_v) return ;// since same component
                else if(size[ulp_u] < size[ulp_v])
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        djs ds(n);
        //lets iterate in the matrix
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                      ds.union_bysize(i,j); // its like if there exists an edge then only we gonna merge
                }
            }
        }
        int count = 0;
        // now lets iterate and find the count of the unique ultimate parents
        //here we gonna iterate on all and check if ultimate boss then only increase count
        for(int i = 0;i<n;i++)
        {
            if(ds.findupar(i) == i)
            {
                count++;
            }
        }
        return count;

        
    }
};