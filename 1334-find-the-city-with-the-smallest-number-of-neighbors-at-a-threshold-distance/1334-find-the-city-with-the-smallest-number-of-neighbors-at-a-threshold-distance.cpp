class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        // graph creation of assigning the edge weights
        for(auto it:edges)
        {
            dis[it[0]][it[1]] = it[2];
            dis[it[1]][it[0]] = it[2]; // here in accountance we are taking the undorected graph here
        }
        // next we will assign the digonal
        for(int i=0;i<n;i++)
        {
            dis[i][i]=0;// we mark it 0
        }

        // now perform the floyd warshall
        for(int via =0 ;via<n;via++)
        {
            for(int i =0;i<n;i++)
            {
                for(int j =0;j<n;j++)
                {
                    if(dis[i][via] == 1e9 || dis[via][j] == 1e9)
                    {
                        continue;// here u just simply count it
                    }
                    dis[i][j] = min(dis[i][j],dis[i][via]+dis[via][j]);
                }
            }
        }

        // next main logic
        int maxi_count = n;
        int city_no = -1;
        //lets iterate in the city and then next to its adjacent cities and for each city count the number of neighbouring cities whose threshold within disthreshold
        for(int city = 0;city<n;city++)
        {
            int c = 0;
            for(int adjcity = 0;adjcity<n;adjcity++)
            {
                if(dis[city][adjcity] <=  distanceThreshold) // we are taking both the cases <=
                {
                    c++;
                }
            }
            // now here do check and updates
            if(c<= maxi_count)
            {
                maxi_count=c;
                city_no = city;
            }
        }
        return city_no;
    }
};