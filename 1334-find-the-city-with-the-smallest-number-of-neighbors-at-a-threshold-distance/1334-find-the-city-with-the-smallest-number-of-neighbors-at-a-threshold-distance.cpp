class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        //creation of the graph
        for(auto it:edges)
        {
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }
        //now same node to node
        for(int i=0;i<n;i++)
        {
            dis[i][i]=0;
        }
        //now applying the floydd warshalls algo
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dis[i][via] == 1e9 || dis[via][j] == 1e9)
                    {
                        continue;
                    }
                    dis[i][j]=min(dis[i][j],dis[i][via]+dis[via][j]);
                }
            }
        }

        //now  final checking
        int city_count=n;
        int city_no=-1;
        //basically city to adjacent city
        for(int city=0;city<n;city++)
        {
            int c=0;
            for(int adjcity=0;adjcity<n;adjcity++)
            {
                //the check of condition part  if the  curr city has its adjacent cities within the threshold_distance  increase count
                if(dis[city][adjcity] <= distanceThreshold)
                 {
                    c++;
                 }  
               // c++;
            }

            //now updation part
            if(c<=city_count)
            {
                city_count=c;
                city_no=city;//the the city with smaller number of adjacents under threshold 
            }
        }
    return city_no;//return the final city

    }
};
