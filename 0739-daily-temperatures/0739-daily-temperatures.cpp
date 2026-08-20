class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>st;
        vector<int>ans(n,0);

        //lets iterate from back
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()]<= temperatures[i])
            {
                //if less and useless 
                //just pop
                st.pop();
            }

            // if  means some warmer temperature exsists
            if(!st.empty())
            {
                ans[i]= st.top() - i;// warmer temp - current temp
            }

            //and we have to push the current indicies may be it can be a good candidate
            st.push(i);
        }
        
        return ans;
    }
};
/* like in this ques we are asked to find the no of days we need to wait for each day 
to get a warmer temperature
=>so something similar to here we have to do like here also nge(temp) on right
=>here also we traverse  from r->l
 */
