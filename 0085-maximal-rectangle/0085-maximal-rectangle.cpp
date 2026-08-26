class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        //we are traversing row wise ..like building the histogram rowise here
        //updating the heights over here
        // and here right boundary sirf columns tak jaeghi
        int r = matrix.size();
        int c = matrix[0].size();

        int maxi_area = 0;
        vector<int>height(c,0); // we gonna make it of column
        for(int i = 0 ;i < r;i++)
        {
            //we gonna build histograms for each current rows
            for(int j = 0; j<c ; j++)
            {
                // so we gonna firstly update the height of vertical consecutive
                if(matrix[i][j] == '1')
                    height[j]++;//increase
                else
                    height[j] = 0;//reset back to 0    

            }

            stack<int>st;
            //next once we have our histogram out of matrix lets traverse and find the largest rectangle in histo
            for(int j = 0;j<=c;j++)
            {
                //traverse till valid index 
                int cur_ht = (j==c)?0:height[j];
                //lets pop till all the tallers bars are resolved
                while(!st.empty() && height[st.top()] > cur_ht)
                {
                    int h = height[st.top()];
                    st.pop();

                    int l = st.empty()?-1:st.top();
                    int r = j;

                    int width = r - l -1;
                    int area = h*width;
                    maxi_area = max( maxi_area,area);
                }

                if(j<c)
                {
                    //means valid wala hi push
                    st.push(j);
                }
            }
        }

        return maxi_area;
    }
};
/*2D Matrix → convert each row into a 1D histogram → apply the exact Largest Rectangle algorithm you just learned.

Matrix
   ↓
Process row by row
   ↓
Maintain vertical consecutive-1 heights
   ↓
Current row becomes a histogram
   ↓
Largest Rectangle in Histogram
   ↓
Get best rectangle whose bottom is current row
   ↓
Update global maximum
   ↓
Next row

[basically we try to update the height of the building its like vertical height update of consecutive ones]

1  → building continues → height++
1  → building continues → height++
1  → building continues → height++
0  →  building breaks → height = 0
1  → new building starts → height = 1

 Vertical consecutive 1s = histogram height.
 Horizontal consecutive bars = rectangle width.


 actual current:
    pop + calculate all
    ↓
    push current

fake 0:
    pop + calculate all
    ↓
    DONE
*/
