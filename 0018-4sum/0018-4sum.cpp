class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        //here we gonna fix two elements here 
        for(int i =0 ;i<n;i++)
        {
            //skip dupliactes for the fixed elements

            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }

            for(int j = i+1 ; j<n;j++)
            {
                //skip duplicates here too for fixed elements theek
                // here also joh sec ele ha woh >i+1 se hona toh chaeya theek 
                if(j>i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }

                //now we gonna set the two pointers 
                int k  = j+1;
                int l = n-1;
                while(k<l)
                {
                    long long sum  = 1ll* nums[i]+nums[j]+nums[k]+nums[l];

                    if(sum < target)
                    {
                        k++;
                    }
                    else if(sum > target)
                    {
                        l--;
                    }
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;

                        //next we need to skip the duplicates of k and l
                        while(k<l && nums[k] == nums[k-1])
                        {
                            k++;
                        }
                        while(k<l && nums[l] == nums[l+1])
                        {
                            l--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};