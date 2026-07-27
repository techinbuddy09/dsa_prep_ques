class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        //here in this question cycle toh we will be having yr 
        //toh phase 1 is to find any meeting point in the cycle

        //we point to the next index value
         int slow = nums[0];
         int fast = nums[0];

         do
         {
            slow = nums[slow];
            fast = nums[nums[fast]];
         }while(slow!=fast);// here we are using do-while loop

         //next phase 2 wherein we gonna try to find the entry point of the cycle
         slow = nums[0];
         while(slow!=fast)
         {
            slow = nums[slow];
            fast= nums[fast];
         }
         return slow;
       
    }
};
