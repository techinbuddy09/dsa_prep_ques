class Solution {
    // now the function for the dfs call
    void dfs(int r ,int c,vector<vector<int>>&vis,vector<vector<char>>& board,int dr[],int dc[])
    {
        int n = board.size();
        int m = board[0].size();
        vis[r][c]=1;// mark as visited initial configuration
        //lets traverse on the adj 
        for(int i =0;i<4;i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc] == 'O')
            {
                dfs(nr,nc,vis,board,dr,dc);
            }
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        //lets iterate in the first row fix row 0 and column chnaging entire check on there only
        for(int j = 0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j] == 'O')
            {
                // do a dfs call
                dfs(0,j,vis,board,dr,dc);
            }
            // now the last row
            // verdict fix last row n-1 and column changes
            if(!vis[n-1][j] && board[n-1][j] == 'O')
            {
                    // do a dfs call here
                    dfs(n-1,j,vis,board,dr,dc);
            }
        }

        // now lets travese in the first column and fix first column
        for(int i = 0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0] == 'O')
            {
                // do a dfs call here
                dfs(i,0,vis,board,dr,dc);
            }

            // next dfs call on the last column fix it and row chnages
            if(!vis[i][m-1] && board[i][m-1] == 'O')
            {
                //do a dfs call here
                dfs(i,m-1,vis,board,dr,dc);
            }
        }

        // next we gonna retraverse and basically the ones which are not visited chnage them to 'X'
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(vis[i][j] == 0 && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};