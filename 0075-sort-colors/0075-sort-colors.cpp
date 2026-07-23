class Solution {
public:
    void sortColors(vector<int>& nums) {
        // here our loop it will run till mid<=high
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        //loop till mid<=high
        while(mid<=high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;// 1 already in correct region so we can safely move
            }
            else if(nums[mid] == 2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
        
    }
};

