class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int count = 0 ;
        for(int x:nums)
        {
            if(count == 0)
            {
                candidate = x;
                count = 1;
            }
            else if(x == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};
