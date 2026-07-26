class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
            maxi = max(sum,maxi);

            if(sum<0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};
// gonna solve this question using the kadanes algorithm hehe
// in the kadanes algo if the running sum which we get is negative so i guess its better not carry it forward and rest our sum to 0 and start a new subarray 
// like suppose sum =-5 theek if i add 10 =>sum =5 but if i reset and create a new =>sum = 10 which is better=>carrying a negative running sum is useless  theek
// we wont reset sum to zero if we see a negative element'
// we reset to 0 only when the running sum is -ve because adding any value to it will only make the future ans smaller 


// when we check for our ans na so firslty we add theek 
//next update the maxi value theek
// after that we check if sum < 0  and reset sum to 0 if -ve 
// because if suppose arrays only has [-2]=> the only ans =-2 na so thats why

//so basically sum = 0 maxi = int_min theek next loop phir sum+=nums[i] .. firstly we will update maxi only maxi = max(maxi,sum) .. and after that we will reset sum to 0 if sum < 0 theek and then return maxi one thing we are updating maxi first because suppose array mein sirf[-2] eak hi toh iska toh max subbaray sum -2 hi ho ga ..and agar mene ohele he -ve running sum dekh ke rest kardiya sum = 0 phir toh it will be wrong hehhe