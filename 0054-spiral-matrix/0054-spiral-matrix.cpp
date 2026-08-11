class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

         // 4 direction variables
         int top = 0; // firts row
         int bottom = n-1; //last row
         int right = m-1; //last col
         int left = 0;// first col

         vector<int>soln;

         while(top<=bottom && left<=right)
         {
            //loop runs till we have remaining rows and columns

            //l->r
            for(int j = left;j<= right;j++)
            {
                soln.push_back(matrix[top][j]);
            }
            top++;// shrinkage

            //t->b
            for(int i = top ;i<=bottom;i++)
            {
                soln.push_back(matrix[i][right]);
            }
            right--;

            //r->l

            // we need to check here then only light kya row aur cols bachi bhi ha before pushing ans
            if(top<=bottom)
            {
                for(int j = right;j>=left;j--)
                {
                    soln.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if(left<=right)
            {
                for(int i = bottom;i>=top;i--)
                {
                    soln.push_back(matrix[i][left]);
                }
                left++;
            }
         }

         return soln;
        
    }
};
