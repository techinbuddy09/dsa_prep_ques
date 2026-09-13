class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        //int n = grid.size();
        int m = grid[0].size();

        // create a temporary matrix
        vector<vector<int>>temp(n,vector<int>(m,0));

        //firstly doing the row shift

        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int nc = (j - rowShift[i] + n)%n;
                temp[i][nc] = grid[i][j];
            }
        }

        //next we will do column shift

        for(int i =0 ;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int nr = (i - colShift[j] + n)%n;
                grid[nr][j] = temp[i][j];
            }
        }

        return grid;
        
    }
};
/* rgrid = n × n matrix
rowShift = har row ko kitna LEFT shift karna hai
colShift = har column ko kitna UP shift karna hai

Aur order fixed hai:

Step 1: Saari rows shift karo
Step 2: Uske baad saare columns shift karo.



//A sample dry run

Step 1 — Row shift

Example:

grid =
1 2 3
4 5 6
7 8 9

rowShift = [1, 2, 0]
Row 0 ko 1 LEFT
1 2 3
↓
2 3 1
Row 1 ko 2 LEFT
4 5 6
↓
6 4 5
Row 2 ko 0
7 8 9

So after row shifts:

2 3 1
6 4 5
7 8 9
Step 2 — Column shift

Ab colShift = [2, 2, 1]

Important: column shift UP hota hai.

Current matrix:

2 3 1
6 4 5
7 8 9
Column 0 ko 2 UP

Column 0:

2
6
7

2 positions UP →

7
2
6
Column 1 ko 2 UP

Column 1:

3
4
8

2 UP →

8
3
4
Column 2 ko 1 UP

Column 2:

1
5
9

1 UP →

5
9
1

Final:

7 8 5
2 3 9
6 4 1


//* so basically acc to the requiremnts of our question we have to process the rows first ...and then net is column theek

=>if we are at a current row we shift that current ith row to the left in the grid by  

=> and the same for columns 

=>baasically we cycle shifting theek 


grid
 ↓
[Row shifts]
 ↓
temp

2 3 1
6 4 5
7 8 9

 ↓
[Column shifts]
 ↓
grid

7 8 5
2 3 9
6 4 1

=>alright so basically what we are doing here is that basically here we are calculating the positions for each row and column and then assigning these each row and col correct positions

=> what we are basically doing here is that eak new matrix mein we are storing the result which we get after the rowshift

=>then using for column shift we are using our original grid matrix and usme bas columns chnage store kar rajhe and updated result we are storing from temp matrix 

rowshit mein columns chnage
columnshift mein rows change

*/

