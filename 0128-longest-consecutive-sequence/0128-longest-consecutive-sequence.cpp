class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //edge case
        
        if(nums.empty())
            return 0;
        int n = nums.size();
        int longest = 0;
        unordered_set<int>st(nums.begin(),nums.end());
        for( auto x:st)
        {
            if(st.find(x-1) == st.end())
            {
                int curnum = x;
                int curlen  = 1;
                while(st.find(curnum+1) != st.end())
                {
                    curlen = curlen+1;
                    curnum   = curnum+1;
                }
                longest = max(longest,curlen);
            }
        }
        return longest;
    }
};