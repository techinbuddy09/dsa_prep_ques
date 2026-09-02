class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // alright so we gonna use the optimized approach over here
        //like usage of prefix product array only
        // like here we can use the left and right prefix product array
        //but usse time complexity will increase too much

        //left array ka computation ans array mein hi
        // and right array ki value computation 1 by one and using a variable
        // and we gonna update it

        //left array in ans->forward
        //right array we compute one by one directly in ans ..using variable ..backward traversing

        int n = nums.size();
        vector<int>res(n);
        res[0] = 1;
        //computing left prefix array in ans[] directly

        for(int i = 1;i<n;i++)
        {
            res[i] = res[i-1] * nums[i-1];
        }

        //next we will directly iterate in nums arr from back ..and update value in array by right variable 
        // and update right variable value with nums with each iteration
        int r = 1;
        for(int i = n-1 ;i>=0;i--)
        {
            res[i]*=r;
            r*=nums[i];
        }

        return res;
    }
};