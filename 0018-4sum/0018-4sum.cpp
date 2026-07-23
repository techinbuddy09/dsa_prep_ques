class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        //firstly we gonna sort the array
        sort(nums.begin(),nums.end());
        // since array sorted we gonna apply two pointer technique over here
        vector<vector<int>>res;// to store the ans
        // fix first element
        for(int i =0;i<n;i++)
        {
            // skip the first fix ele duplicate to avoid , in order to avoid duplicates
            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }

            //next we gonna fix the second element 
            for(int j = i+1;j<n;j++)
            { 
                //skip  the second fix element  to avoid duplicates
                if(j>i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }

                // next we gonna set the two pointers 
                int k = j+1;
                int l = n-1;

                // now calculate the sum value
                // here to overcome the integer overflow we have this long long and force long type multiplication
                 //long long sum = 1LL*nums[i]+nums[j]+nums[k]+nums[l];

                 //now lets traverse
                 while(k<l)
                 {
                    // always calc sum na
                     long long sum = 1LL*nums[i]+nums[j]+nums[k]+nums[l];

                     if(sum < target)
                     {
                        k++;
                     }
                     else if (sum > target )
                     {
                        l--;
                     }
                     else
                     {
                        res.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        // move both the pointers  to avoid duplicates 
                        // next inner loop moving of k and l to avoid 
                        while(k<l && nums[k] ==  nums[k-1])
                        {
                            k++; // to avoid
                        }

                        while(k<l && nums[l] == nums[l+1])
                        {
                            l--;
                        }
                      } 
                 }
        
           }
        }
        return res;  // now return the res vector      
    }   
};
// here we are are storing quadruplets.{group of 4}
// here to avoid integer oveflow we are using long long for it 