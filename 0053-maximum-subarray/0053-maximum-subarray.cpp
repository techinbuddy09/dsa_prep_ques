class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi = max(sum,maxi);// do the updation before only theek

            //now rest -ve running sum to 0
            if(sum < 0)
            {
                sum = 0;
            }
        }
        
        return maxi;
    }
};
/*alright the main intuition in this ques is 
//  in this we carry the running sum of the subarray theek
//if the current running sum it is < 0  means negative its useless to carry it forward
-because a -ve running sum will only reduce our future ans theek
- so its better toh reset the sum back to 0 and do fresh start with a new subaary and new element
-like suppose sum = -5 and next ele = 10
-if we carry this our sum becomes 5 ..our future is reduced na
-but what if we rest our sum to 0 ..and do a fresh start here theek
- so now our sum = 10 ..something a better result

-also an edge case here in this we gonna update our maxi befoe..reset our current running sum ..theek becuase suppose our subaarray only has
[-2] theek so here agar we didnt updated andrun our ..rest sum logic isse we got our max sum ans as 0...but that ans is wrong like the only element which we have is -2 so ..isliya sometimes before reset ..we update before hand
*/