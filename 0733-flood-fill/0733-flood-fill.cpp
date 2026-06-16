class Solution {
    void dfs(int r,int c,vector<vector<int>>&image,vector<vector<int>>&ans,int dr[],int dc[],int new_color,int i_c)
    {
        int n = image.size();
        int m = image[0].size();
        //initial configuration
        ans[r][c] = new_color;
        //next traverse on the adjacnet and if they are not yet visited do the color change on them to recursilvey and also the adjacent should be e to the color of initial color
        for(int i = 0;i<4;i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc] != new_color && image[nr][nc] == i_c)
            {
                // do the further dfs call
                dfs(nr,nc,image,ans,dr,dc,new_color,i_c);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int initial_color = image[sr][sc];
        vector<vector<int>>ans = image ;// copy of the image array so that we can do the modifications here of the color
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        //now here lets do the dfs call  here
        dfs(sr,sc,image,ans,dr,dc,color,initial_color);
        return ans;//return the modified ans vector
                         }
};
