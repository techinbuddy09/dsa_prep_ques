class Solution {
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>& grid,int dr[],int dc[])
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;
        for(int i = 0;i<4;i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == 1)
            {
                dfs(nr,nc,vis,grid,dr,dc);
            }
        }

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        //lets iterate in the first row fix row 0 and column chnaging entire check on there only
        for(int j = 0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j] == 1)
            {
                // do a dfs call
                dfs(0,j,vis,grid,dr,dc);
            }
            // now the last row
            // verdict fix last row n-1 and column changes
            if(!vis[n-1][j] && grid[n-1][j] == 1)
            {
                    // do a dfs call here
                    dfs(n-1,j,vis,grid,dr,dc);
            }
        }

        // now lets travese in the first column and fix first column
        for(int i = 0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0] == 1)
            {
                // do a dfs call here
                dfs(i,0,vis,grid,dr,dc);
            }

            // next dfs call on the last column fix it and row chnages
            if(!vis[i][m-1] && grid[i][m-1] == 1)
            {
                //do a dfs call here
                dfs(i,m-1,vis,grid,dr,dc);
            }
        }

        // next we gonna retraverse and basically the ones which are not visited chnage them to 'X'
        int c = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(vis[i][j] == 0 && grid [i][j] == 1)
                {
                    c++; // to store the count the no of land cells which we cannot walk off the boundary of grid
                }
            }
        }
        return c;
    }
        
};