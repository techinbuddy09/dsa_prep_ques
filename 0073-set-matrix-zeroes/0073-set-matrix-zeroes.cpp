class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        //col0 marker
        //initially set at 1 means not original 0 is present there
        int col0 = 1;

        //lets traverse and do scan and mark the markers over here 
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    // here a special case like suppose col koi 0 ha
                    if(j == 0)
                    {
                        col0 = 0;// means original 0 seen
                    }
                    else
                    {
                        //mark the row and column marker
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        // next step we gonna use these markers to mark the inner cells 0
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<m;j++)
            {
                // for any cell if marker r or c is 0 toh mark it 0
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        //next handling the 0th row and 0th col

          if(matrix[0][0] == 0) // means original 0 was present
        {
            //lets iterate on col and make entire row as 0
            for(int j = 0;j<m;j++)
            {
                matrix[0][j] = 0;
            }
        } //ow fix and col changing


        if(col0 == 0) // means original 0 was present
        {
            //lets iterate on row and make entire row as 0
            for(int i = 0;i<n;i++)
            {
                matrix[i][0] = 0;
            }
        }

    }
};
// we will firstly handle the 0th row 
// then next we will mark 0th column