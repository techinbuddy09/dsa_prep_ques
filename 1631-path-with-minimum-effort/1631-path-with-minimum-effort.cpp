class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        //initial configurations
        dis[0][0] = 0;
        pq.push({0,{0,0}});

        // lets iterate in the queue
        while(!pq.empty())
        {
            auto it = pq.top();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();

            // here only we check if we reached our destination we gonna return dis
            if( r == n-1 && c == m-1)
            {
                return diff;
            }

            // next we gonna traverse on the adjacent
            for(int i = 0;i<4;i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];

                // boundary checks
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    // we gonna calculate the new effort here 
                    int n_eff = max(abs(heights[r][c]-heights[nr][nc]),diff);
                    if(n_eff<dis[nr][nc])
                    {
                        dis[nr][nc]=n_eff;
                        pq.push({n_eff,{nr,nc}});
                    }
                }
            }
        }
        // if nothing simply return 0
        return 0;
    }
};
// if the route doesnt require any effort simply return 0 here