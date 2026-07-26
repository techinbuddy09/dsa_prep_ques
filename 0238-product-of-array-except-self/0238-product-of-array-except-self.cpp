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

// product array is like for each idx we multiply all elements except the current nums

// here we can compute the left array and the right array
// and then next for each index left array * right array


/*vector<int> left(n);
vector<int> right(n);
vector<int> ans(n);

left[0] = 1;
for(int i = 1; i < n; i++)
{
    left[i] = left[i-1] * nums[i-1]; // not including number itself isliya i-1
}

[1,2,3,4]  =>[1,1,2,6]

right[n-1] = 1;
for(int i = n-2; i >= 0; i--)
{
    right[i] = right[i+1] * nums[i+1];
}

[1,2,3,4] =>[24,12,4,1]

for(int i = 0; i < n; i++)
{
    ans[i] = left[i] * right[i];
}

[1,2,3,4]=>[24,12,8,6] done hehe

// optimization like now not using separate left and right array
means basically firstly we eliminated extra left array creation by using our ans array as left array only next as we dont want the entire right array atb once so instead of creating the entire right array at once we maintained a variable right initially with 1 next we start iterating in nums theek and firsly in the value at the right array index we multiply it by right variable value next update the right variable index value with value in nums[i] and here we are iterating nums frommbackward so in this way we have reduced our extra space complexity of creating two separate left and right arrays hehe

*/

