class Solution {
public:
    int firstMissingPositive(vector<int>&nums) {

        // since we want everything to check in the range [1 n] 
        // so basically we gonna iterate and mark all the invalids ko positive
         //step -1
         int n = nums.size();

       // so basically in this ques if suppose we have a tc like 
       //[7,8,9,11,12] where no one is => the smallest first positive will be 1 so return 1 auyomatically 
       // and is one is present to phir pura process karo 1 to n ka
       bool hasone =  false;
       for(int x:nums)
       {
        if(x == 1)
        {
            hasone  = true;
            break;
        }
       }

       if(!hasone)
            return 1;

         for(int i = 0;i<n;i++)
         {
            if(nums[i] <= 0 || nums[i] > n)
            {
                nums[i] = 1;
            }
         }

         // next step 2 we will marks the  index
         for(int i =0;i<n;i++)
         {
             int x = abs(nums[i]);
             nums[x-1] = -abs(nums[x-1]);
         }

         // step 3 reiterate again return first +ve
          for(int i =0;i<n;i++)
          {
            if(nums[i] > 0)
            {
                return i+1;// since idx = i-1 na so here no =+1
            }
          }
          // if nothing return max possible
          return n+1;
        
    }
};
