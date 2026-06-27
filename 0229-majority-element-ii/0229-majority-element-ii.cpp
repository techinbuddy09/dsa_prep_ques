class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n =nums.size();
        int c1 = 0 ;
        int c2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        vector<int>res;
        for(int  i =0;i<n;i++)
        {
            if(ele1 == nums[i])
            {
                c1++;
            }
            else if(ele2 == nums[i])
            {
                c2++;
            }
            else if(c1 == 0  && ele2!=nums[i])
            {
                c1 = 1;
                ele1 = nums[i];
            }
            else if(c2 ==  0 && ele1!=nums[i])
            {
                c2 = 1;
                ele2 = nums[i];
            }
            else
            {
                // completely different element
                c1--;
                c2--;
            }
        }

        // now we gonaa retraverse
        int c11 = 0;
        int c21 =0;
        int mini = (n/3)+1;
        for(int i = 0;i<n;i++)
        {
            if(ele1 ==  nums[i])
            {
                c11++;
            }
            if(ele2 == nums[i])
            {
                c21++;
            }
        }

        // now condition chexk
        if(c11>= mini)
        {
            res.push_back(ele1);
        }
        if(c21 >= mini)
        {
            res.push_back(ele2);
        }

        return res;

    }
};