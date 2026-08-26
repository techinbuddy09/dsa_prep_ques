class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //we gonna maintain a monotonic stack over here
        // pattern nse on right
        // so traverse effectively from right->left
        stack<int>st;
        int n = prices.size();
        vector<int>ans(n);//make it of the smae size as prices to store ans with discount applied
        for(int i = n-1;i>=0;i--)
        {
            int current_ele = prices[i];

            //now lets iterate and pop all the ones which are > current
            while(!st.empty() && st.top() > current_ele)
            {
                st.pop();
            }

            //next if suppose stack empty => no discount offered over here
            if(st.empty())
            {
                ans[i] = prices[i];// means 0 discount => will have the same amount of the prices over here
            }
            else
            {
                // if stack is not empty => discount is applied
                ans[i] = current_ele - st.top();
            }

            //next we gonna push the current for the future ones to process
            st.push(current_ele);
        }

        return ans;
    }
};
/*
For every item, we look to its right and find the first price ≤ current price.
That price becomes the discount.
for nge on left we traverse from left to right
for the nse on left and right we traverse from right to left theek for maintaining efficient monotonic stack theek

RIGHT → LEFT
     ↓
pop all > current
     ↓
stack empty?
   ↓       ↓
  YES      NO
   ↓        ↓
discount  stack.top()
 = 0        ↓
       current - top
     ↓
push current
*/