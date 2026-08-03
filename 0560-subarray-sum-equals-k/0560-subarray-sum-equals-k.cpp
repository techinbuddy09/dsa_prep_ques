class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int cur_prefix_sum = 0;
        int count = 0;
        for(int num:nums)
        {
            cur_prefix_sum+=num;
            //next calculate the previous prefix sum
            int prev_prefix_sum =  cur_prefix_sum - k;
            // now check whether it exists in the map
            //if yes add the frequency to the count
            //else add the current prefix sum
            if(mp.find(prev_prefix_sum)!= mp.end())
            {
                count+=mp[prev_prefix_sum];
            }
            //update
            mp[cur_prefix_sum]++;
        }

        return count;
    }
};
//  previous_prefix = current_prefix-k
// edge case case when current_prefix_sum == k
//Before traversing the array, we assume an imaginary index -1 having a prefix sum of 0. Therefore, whenever currentPrefixSum == k, the subarray starting from index 0 is also counted correctly. This is why we initialize mp[0] = 1.
