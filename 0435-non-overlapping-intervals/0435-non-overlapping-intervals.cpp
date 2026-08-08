class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // need to sort the intervals on start like we are comparing on start time
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();

        int prevend = intervals[0][1];// previous end storing basically focus on the ending
        int count = 0;
        //next lets iterate from 1
        for(int i =1;i<n;i++)
        {
            //firstly check whether the intervals overlap 
            // if the current ka start is smaller then previous la end so yes
            if(intervals[i][0] < prevend)
            {
                // if yes means overlapping of intervals means we need to remove the the larger end wala and keep the maller end wala
                count++;// means removed one interval storing count here
                // next we update the prevend for doing comaprison with the next iteration
                prevend = min(prevend,intervals[i][1]);
            }
            else
            {
                //no overlap 
                // means the current intervals survives
                prevend = intervals[i][1];
            }
        }
        return count;
        
    }
};
