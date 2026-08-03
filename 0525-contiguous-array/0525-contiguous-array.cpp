class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int prefix_sum = 0;
        int max_len = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;//prefix sum = 0 for the imaginary index

        for(int i = 0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                prefix_sum+=-1;
            }
            else
            {
                prefix_sum+=1;
            }

            // next lets locate for this prefix_sum in the hash map
            if(mp.find(prefix_sum)!= mp.end())
            {
                max_len = max(max_len,i-mp[prefix_sum]);// here we are storing the first index of occurance
            }
            // if not found create one with default and update the index
            else
            {
                mp[prefix_sum] = i;
            }   
        }
        return max_len;//here we will return the max length of the contiguous subarray
        
    }
};
