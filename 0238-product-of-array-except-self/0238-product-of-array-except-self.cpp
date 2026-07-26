class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // here comes the optimized code
        // instead of creating a separate left arry storing product of left elements
        // we are going to store the products of the left array directly in the ans array itself
        int n = nums.size();
        vector<int>ans(n);
        ans[0] = 1;

        for(int i =1;i<n;i++)
        {
            ans[i] = ans[i-1]*nums[i-1];
        }

        // next instead of creating a separate right array for right products
        //we gonna use a variable and will create right array along like not all at  once

        int right = 1;
        for(int i =n-1;i>=0;i--)
        {
            ans[i] = ans[i]*right;
            right = right * nums[i];//update the right which basically hold the product of all the elemnts on the right itslef
        }
        return ans;
    }
};
