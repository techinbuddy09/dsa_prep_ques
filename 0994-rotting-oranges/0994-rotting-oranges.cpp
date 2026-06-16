class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int t_max = 0;
        //lets iterate in the matrix
        for(int i = 0 ;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    // if rotten encountered
                    // push in queue and mark it visited
                    //initial configuration
                    q.push({{i,j},0});//{{r,c},t_max}
                    vis[i][j]=2;//make it rotten too
                }
                //if not keep it as the initial configuration
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        //now lets iterate in queue and apply multi-source bfs
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            
            t_max=max(t_max,t);// update the time after every bfs call
            q.pop();
            //now lets traverse on the adjacent  neighbours
            for(int i = 0 ;i<4;i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];

                // now bound checks
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=2 && grid[nr][nc] == 1)
                {
                    // again push in queue and mark it as visited
                    q.push({{nr,nc},t_max+1});
                    vis[nr][nc] = 2;
                }
            }
        }
        // now we will retraverse to find if any fresh mango left and we were not able to rot so return -1
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 &&vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        // if not return the t_max time here
        return t_max;
        
    }
};