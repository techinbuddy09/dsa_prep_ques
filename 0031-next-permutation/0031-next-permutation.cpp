class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        //step 1 firstly we are going to find the pivot index or the breakeven point
        int break_point = -1;
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                break_point = i;
                break;
            }
        }

        // step 2 if suppose no pivot this => it is the last permutation so we have the entire
        // decreasing suffix so we will simply reverse the whole array

        if(break_point == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        //step 3 after finding the pivot next we will find the first smallest greater element than pivot_idx

        for(int i = n-1;i>break_point;i--)
        {
            if(nums[i]>nums[break_point])
            {
                swap(nums[i],nums[break_point]);
                break;
            }
        }

        //step 4 we gonna reverse the array after the pivot till end mtlb arrange the decreasing suffix in ascending order
        reverse(nums.begin()+break_point+1,nums.end());
        
    }
};

