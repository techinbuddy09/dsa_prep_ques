class Solution {
public:
 //here we gonna apply the Dutch National Flag Algorithm
    void sortColors(vector<int>& nums) {
        int n=nums.size();//to find the size of the array
        int low=0;
        int high=n-1;
        int mid=0;//setting both the low and mid at 0
        while(mid<=high)//loop terminates once mid<=h
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            } 
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
        
    }
};