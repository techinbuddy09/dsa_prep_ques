class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        //next we gonna sort the array
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
        //lets iterate 
        for(int i =0 ;i<n;i++)
        {
            //firstly skip the duplicates for the fixed elements
            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }

            //next we gonna set the two pointers here theek
            int left = i+1;
            int right = n-1;

            while(left<right)
            {
                int sum = nums[i]+nums[left]+nums[right];// waise our target is 0 theek and here nums[i] is the fix element which we keep one by one and calc
                if(sum < 0)
                {
                    //need bigger move left
                    left++;
                }
                else if(sum > 0)
                {
                    right--;
                }
                else
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;

                    //now before moving to other we need to skip the duplicates for left and right
                    while(left<right && nums[left] == nums[left-1])
                    {
                        left++;
                    }

                    while(left<right && nums[right] == nums[right+1])
                    {
                        right--;
                    } 
                }
            }

        }

        return ans;
    }
};