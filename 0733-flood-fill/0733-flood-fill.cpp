class Solution {
    private:
    //always pass by refernece else will create copy
        void dfs(int r,int c,vector<vector<int>>&image,vector<vector<int>>&vis,int dr[],int dc[],int new_col , int i_c)
        {
            vis[r][c]=new_col;//filling with the new color
           int n=image.size();
           int m=image[0].size();
           //now iterating on the adjacent ones
           //iterating in the  four directions
           for(int i=0;i<4;i++)
           {
            int nr=r+dr[i];
            int nc=c+dc[i];
            //now condition check+rest other if adjacent equals to i_c and not visited too
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == i_c && vis[nr][nc]!=new_col)
            {
                dfs(nr,nc,image,vis,dr,dc,new_col,i_c);
            }
           }

        }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int i_c=image[sr][sc];// the initial color
        //vis array for the replica array
        vector<vector<int>>ans=image;//creation of the replica array
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        //call the dfs 
        dfs(sr,sc,image,ans,dr,dc,color,i_c);
        return ans;
      }
};
