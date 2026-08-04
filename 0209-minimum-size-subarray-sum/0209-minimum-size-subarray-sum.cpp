class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        //before calc shrink or expand we need to have a window 
        // we need to create a window and then calc sum of it 
        // and on that we check like we need to have a window before hand
        for(int right =0;right<n;right++)
        {
            // firstly we create the window
            sum+=nums[right];

            //got a valid ans so store first next shrink
            while(sum>=target)
            {
                ans = min(ans,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        // if suppose nothing return 0
        if(ans == INT_MAX)
            return 0;
        return ans;    
        
    }
};
