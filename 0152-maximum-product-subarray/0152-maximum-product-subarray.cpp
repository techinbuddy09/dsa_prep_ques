class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = nums[0];
        int curr_min = nums[0];
        int res = nums[0] ;// nums[0] for edge case like only on element in thesubarrays

        for(int i = 1;i<nums.size();i++)
        {
            // store the values first before updating
            int x = nums[i];
            int tempmax = curr_max;
            int tempmin = curr_min;

            //now update curmax and min basically the max and min product of the subbary at the current index not entire
            // curr_min we took for -ve*-ve =>max +ve product of subarray
            curr_max = max({x,tempmax*x,tempmin*x});
            curr_min = min({x,tempmax*x,tempmin*x});
            res = max(res,curr_max);
        }

       // res = max(res,curr_max);
        return res;
        
    }
};
