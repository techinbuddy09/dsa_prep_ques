class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        // no :idx
        for(int i=0;i<n;i++)
        {
            int rem  =  target - nums[i];
            if(mp.find(rem)!= mp.end())
            {
                // return idx of {prev ele,curr_ele}
                return {mp[rem],i};
            }
            //else update 
            mp[nums[i]] = i;
        }
        
        // if nothing 
        return {-1};
    }
};
// solving two_sum by hashing
