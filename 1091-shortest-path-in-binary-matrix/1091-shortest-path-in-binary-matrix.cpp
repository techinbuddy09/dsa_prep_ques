class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m = grid[0].size();
        pair<int,int>src={0,0};
        pair<int,int>des={n-1,m-1};
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        //initial configurations
        dis[src.first][src.second]=1;
        q.push({1,{src.first,src.second}});
        // edge casees
        if(grid[src.first][src.second] == 1 || grid[des.first][des.second] == 1)
        {
            // if the start cell aur destination cell is we wont be able to visit that
            return -1;

        }
        if(src.first == des.first && src.second == des.second)
        {
            return 1;
        }
        while(!q.empty())
        {
            int d = q.front().first;
            int r =q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            //clockwise traversal here
            int dr[]={-1,-1,-1,0,1,1,1,0};
            int dc[]={-1,0,1,1,1,0,-1,-1};

            // now lets traverse in the 8 direction here
            for(int i =0 ;i<8;i++)
            {
                int nr = r+dr[i];
                int nc =c+dc[i];

                if(nr>=0&&nr<n && nc>=0&&nc<m && grid[nr][nc] == 0 && d+1<dis[nr][nc])
                {
                    // update it in the distance array
                    dis[nr][nc] = d+1;

                    // edge case
                    // basically here we check on the nr and nc 
                    if(nr == des.first && nc == des.second)
                    {
                        return d+1;// immidiately break out of the algo
                    }
                    // if not push it in the queue
                    q.push({d+1,{nr,nc}});
                }
            }
        }
        // if nothing 
        return -1;
        
    }
};
// visited cells are only 0 so we can traverse only on the