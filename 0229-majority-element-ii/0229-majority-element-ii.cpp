class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //At most 2 elements can appear more than n/3 times.
        int candidate1 = 0;
        int candidate2 = 1;
        int c1 = 0;
        int c2 = 0;
        for(int x:nums)
        {
            if(x == candidate1) 
            {
                c1++;
            }
            else if(x == candidate2)
            {
                c2++;
            }
            else if(c1 == 0)
            {
                candidate1 = x;
                c1 =1;
            }
            else if(c2 == 0)
            {
                candidate2 = x;
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        // phase 2 verfify
        c1 =0;
        c2 =0;
        vector<int>ans;
        for(int x:nums)
        {
            if(x ==  candidate1)
            {
                c1++;
            }
            else if(x == candidate2)
            {
                c2++;
            }
        }



///basically weare checking over here na so aise 

        if(c1 > nums.size()/3)
        {
            ans.push_back(candidate1);
        }
         if(c2 > nums.size()/3)
        {
            ans.push_back(candidate2);
        }

        return ans;
    }
};
