class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi_area = 0;
        stack<int>st;

        //lets iterate on entire
        for(int i =0 ;i<=n ;i++)
        {
            // we gonna pretend the height as 0 if right boundary = n
            int cur_ht = (i == n)?0:heights[i];

            //next pop all the tall bars'+
            while(!st.empty() && heights[st.top()] > cur_ht)
            {
                int h = heights[st.top()] ;
                st.pop();

                int l_b = st.empty()?-1:st.top();
                int r_b = i;

                int width = r_b - l_b -1;
                int area  =  h*width;
                maxi_area = max(maxi_area,area);
            }
            //once all the tall bars are popped
            st.push(i);
        }
        return maxi_area;    
    }
};
/*
For every bar, treat its height as the rectangle's height. Expand left and right through bars ≥ its height. The first smaller bar on each side stops the expansion.

Therefore:

Nearest Smaller Left
        ↓
      [BAR]
        ↓
Nearest Smaller Right

And:

width = NSR - NSL - 1

area = height × width

For every bar, find where its rectangle ends on the right — i.e. when we encounter a smaller bar.

=>When a smaller element arrives, it resolves all taller bars sitting on top of the stack.

one smaller elements it can resolve multiple heights yr ....all the max heights at the top of stack gets resolved heheheh

[2,1,5,6,2,3]  idx of 5 - 2  and right = 4-1-1=2*5=10

????????????????????????????????????????????????????????????????????

When a bar is popped:

             current smaller
                  ↓
... [left smaller] [BAR] ... [current]

We now know both boundaries.

Right boundary

The current index:

right = i

because current bar is smaller.

Left boundary

After popping, the new stack top:

left = stack.top()

because the stack contains increasing heights, and that top is the nearest smaller bar to the left.

Therefore:

width = right - left - 1

and:

area = height × width

2 → waiting
5 → waiting
3 → "5, your right boundary has arrived"
      ↓
    pop 5
      ↓
calculate 5's area
      ↓
push 3

Process ALL possible pops first → calculate every popped bar's area → then push the current index once. 🔥

At the end:

fake bar height = 0
fake bar index = n

So:

0 height → causes all remaining taller bars to pop
n index → becomes their right boundary

index:   0  1  2  3  4  5 | 6
height:  2  1  5  6  2  3 | 0
                              ↑
                         right boundary

0 → tells us "POP!"
n → tells us "your right boundary is here!"
*/
