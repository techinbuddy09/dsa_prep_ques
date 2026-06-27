class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =  nums.size();
        int c1 = 0;
        int ele;
        for(int i = 0;i<n;i++)
        {
            if(c1 == 0)
            {
               ele = nums[i];
                c1 = 1;
            }
            else if( ele  ==  nums[i])
            {
                c1++;
            }
            else
            {
                c1--;
            }
        }

        int c2 = 0;
        for(int i =0;i<n;i++)
        {
            if(ele  == nums[i] )
            {
                c2++;
            }
        }
        
        // now here we gonna do a simple check
        if(c2 > n/2)
        {
            return ele;
        }
        // if not
        return -1;
        
    }
};