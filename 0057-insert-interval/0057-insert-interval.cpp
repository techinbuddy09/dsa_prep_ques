class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        //vector to store the ans 
        vector<vector<int>>ans;
        int n = intervals.size();
        int i =0;//pointer to iterate over
        //phase 1 we gonna add all those intervals which are before the new intervals 
        while(i<n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        //next is the phase 2 add those intervals which are overlapping and merge them and update the new interval

        while(i<n && intervals[i][0] <= newInterval[1])
        {
            //update both start and end
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }

        //firtly we gonna push _back the updated new interval
        ans.push_back(newInterval);

        // next we gonna run a  loop and push all the remaining intervals greater one
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
        
    }
};
\
