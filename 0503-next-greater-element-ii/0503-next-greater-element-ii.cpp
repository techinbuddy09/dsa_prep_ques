class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n,-1);

        //lets oretend our arary for wrapping around the begining
        for(int i = 2*n-1;i>=0;i--)
        {
            //take the curr ele with original array index
            int curr = nums[i%n];

            //next nge 1 logic
            while(!st.empty() && st.top()<= curr)
            {
                st.pop();//pop till we dont get the greater element on the right
            }

            // and push only when valid index
            if(i<n && !st.empty())
            {
                ans[i] = st.top();
            }


            // we also need to push in stack too the element
            st.push(curr);
        }

        return ans;

        
    }
};
/*here so basically this ques it is very similar  to part1 the only diff here we have is that in this  the array it is circlar => like suppose we have this arrays [1,2,1] so here if we look into this  the last  1 if we look it from nge1=> 1 it has no nge on right => nge(1) = -1 but if we look into the nge2 here we have cicrcular array => the last 1 it will point back to the begining => last 1->1 and the first 1(nge) = 2=> last 1 also has the nge as 2
=> our ans [2,-1,2]
=> if suppose we have reached the ending ..how comp will know so that it point back to begining na
=> so basically what we gonna  do is that we gonna imagine our array two times
=>like our arrays its wrapped around the begining
=>[1 2 1 1 2 1] => so here we have  
   1->2
   2->-1
   1->2
   .....

eg 2 [3 1 2] => [-1,2,3] ...like when i reached 2 it wraps around begining that is 2->wrap->3 ..and we will use same logic of nge1 and here 3 >2 =>nge of 2= 3 na 

Look to the right
→ if array ends
→ wrap to beginning
→ continue

=> now in our ques we are not going to real image..bas we will make the array size 2*n
And the values repeat:

index:    0 1 2 3 4 5
value:    1 2 1 1 2 1

Notice:

0 % 3 = 0 → nums[0] = 1
1 % 3 = 1 → nums[1] = 2
2 % 3 = 2 → nums[2] = 1
3 % 3 = 0 → nums[0] = 1
4 % 3 = 1 → nums[1] = 2
5 % 3 = 2 → nums[2] = 1

So:
mtlb 3/0
[i % n] gives us the corresponding original-array index.


=> the only difference we have is that
==>in the nge 1 we work on original nums array

=>but in nge2 since we had circular array na toh when we reached end na we need to wraap around the begining =>here we gonna our array
->means we will have 2*n elements here
->here we use i%n in order to get the original array idx hehe
ham back se start pura process larenge ..like last ka warrping around begining ha an...but since i>n ho ga ..as its pretended one wala na ..toh we will not not add in ans ..but yes push in stack and yes follow the exact same logic ..
*/
