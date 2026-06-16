class Solution {
    void bfs(int r , int c, vector<vector<int>>&vis,vector<vector<char>>& grid)
    {
        //initial configuration
        vis[r][c] = 1;//mark it as visited
        queue<pair<int,int>>q;
        q.push({r,c});
        int n = grid.size();
        int m = grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        // traverse in the queue
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // traverse on the adjacent neighbours
            // in 4 directions
            for(int i = 0 ; i<4;i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];

                // now check the condition for bounds||vis||aur land
                if(nr>=0 && nr<n && nc>=0 && nc<m &&!vis[nr][nc] && grid[nr][nc] == '1')
                {
                    // first mark it as visited
                    vis[nr][nc] = 1;
                    // next push them in the queue
                    q.push({nr,nc});
                }
            }
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;
        //lets traverse in the matrix
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    // if not visited then call bfs call
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
    return count;

    }
};