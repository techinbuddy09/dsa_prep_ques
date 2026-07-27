class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = -1;
        //lefts insert everything in map
        for(int& no:nums)
        {
            mp[no]++;

            if(mp[no]>1)
            {
                return no;
                break;
            }
        }
        return -1;
    }
};
// here we gonna learn the algorithm Floyd's Cycle Detection