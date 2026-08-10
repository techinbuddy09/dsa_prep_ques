class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // firstly we gonna swap the matrix
        int n = matrix.size();
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                // in transpose of the matrix we swap the upper triangle with the lower triangle

                swap(matrix[i][j],matrix[j][i]);
            }
            // next we gonna reverse each row over here

            reverse(matrix[i].begin(),matrix[i].end());
        }// so ya we did this ques inplace
    }
};
