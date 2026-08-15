class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_range = 0;
        int xor_arr = 0;
        for(int i = 0;i<=n;i++)
        {
            xor_range^=i;
        }
        for(int no:nums)
        {
            xor_arr^=no;
        }
        return xor_range^xor_arr;
        
    }
};
