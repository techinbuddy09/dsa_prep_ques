class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort the intervals first
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;
        //lets push the first interval in ans  for comapring with current interval
        ans.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++)
        {
            //lets comapare
            if(intervals[i][0] <= ans.back()[1])
            {
                // if so means we can merge the overlapping intervals
                //we gonna extend our end to max
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
            else

            {
                // if no overlapping in that case we gonna make a new interval
                ans.push_back(intervals[i]);
            }
        }

         return ans;
    }
};
