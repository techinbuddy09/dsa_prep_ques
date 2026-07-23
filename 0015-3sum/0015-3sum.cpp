class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        
        //sort nums array
        sort(nums.begin(),nums.end());
        // fix the first element
        for(int i = 0;i<n;i++)
        {
            //firstly we will skip the duplicate fix element
            if(i>0 && nums[i] == nums[i-1])
                    continue;
            //next lets set two pointer
            int left = i+1;
            int right = n-1;

            while(left<right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum < 0)
                {
                    left++;
                }
                else if(sum > 0)
                {
                    right--;
                }
                else
                {
                    //means found a triplet where the sum is 0 with fixing that one element
                    res.push_back({nums[i],nums[left],nums[right]});
                    //next to avoid duplicates move the both pointers
                    left++;
                    right--;
                    // also case to avoid ineer loop duplicates
                    while(left<right && nums[left] == nums[left-1]) // like same value on pointer to if we use again it will give same ans means duplicates so we need to avoid it
                    {
                        left++;
                    }

                     while(left<right && nums[right] == nums[right+1]) // like same value on pointer to if we use again it will give same ans means duplicates so we need to avoid it
                    {
                        right--;
                    }

                }
            }        
        }

        return res;// the final vector storing the unique triplets

        
    }
};