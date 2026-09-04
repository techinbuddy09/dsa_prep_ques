class Solution {
public:
    int climbStairs(int n) {
        // firstly the edge case here 

        if(n == 1 || n == 2)
                return n;

         //next we create a dp[] of n+1 like we want one base indexing like step 
         //step 1,2,3,4...
         vector<int>dp(n+1);
         // our recurrence relation it will start from step 3
         dp[1] =1;
         dp[2] = 2;// need  to store this earlier ..varna process kaise ho ga
         for(int i = 3;i<=n;i++)
         {
            dp[i] = dp[i-1]+dp[i-2];
         }      
         return dp[n];// last step tak  reach karne ki distinct number of ways
    }
};
/*You have a staircase with n steps.

You can climb either:

1 step at a time
2 steps at a time
........................................................................................

we basically need to find in how many distinct ways we will be able to reach top

suppose n = 2 so no ways we have is 1) 1->1 steps  (2) 2 steps => we have 2 distinct ways 

........................................................................................

Since every move can only be 1 step or 2 steps, if we're at step n, our last move must have come from either n-1 or n-2.

.......................................................................................

dp[i] = number of distinct ways to reach step i.

........................................................................................

dp[1] = ways to reach step 1  ....basically the no of distinct ways to reach top
dp[2] = ways to reach step 2
dp[3] = ways to reach step 3
...
dp[n] = ways to reach the top means n 
........................................................................................

alright so basically what intuition i got over here is that firstly we know our constraints is that  in order to reach top we can climb either 1 step or 2 step theek..so if we are at step i to we have have reached their from either of last positions one is i-1 and other is i-2 theek ...and further woh i-2 and i-1 bhi also took some ways to reach toh we take take that+ the current amount of jump we took to reach theek .. here dp[i] basically represents the distinct ways to reach to reach step i theek .. lets take an example like suppose we are at step 3 theek toh in order to reach step 3 we have possible two ways 1 is to climb 1 step from 2->3 ..but in order to reach step 2 ...we have basically two ways one is 1->2 like like 1 jump then 1 more jump ....and other is direct 2 by taking 2 jumps =>now in order to reach step 3 if we look to the first way where we took 1 step from 2->3 we got two ways to reach there ..including 3 which becomes 1->2->3 ,2->3...now next possible way is to take two jumps from step 1 to step 3 ...and here also to reach step we have only 1 way to reach =>it becomes 1->3 ...way to reach step 3 .. so overall in order to reach step 3 (i).. no of distinct ways are ,,dp[i-1]+dp[i-2]=>dp[2]+dp[1] ... where no of distinct ways of 2 are 2 and for 1 its is 1=>2+1 = 3...=>3 distinct ways to reaach step 3
.........................................................................................
dp[i] = number of distinct ways to reach step i

         i
        / \
      i-1  i-2
       ↓    ↓
    +1 jump +2 jump

dp[i] = dp[i-1] + dp[i-2]...

basically  each (i-1) creates one new way to reach step i by adding 1 jump
similarly each (i-2) creates a one new way to reach step i by adding 2 jumps
....................................................................................

// for the base case dp[1] means to reach step 1 we require only 1 jump
// then for dp[2] means to reach step 2 we have 2 distinct ways  1->2,direct 2 by taking 2 jumps

// the actual reccurrence starts from step 3
dp[i] = dp[i-1]+dp[i-2]......loop starts from 3->n
.......................................................................................

*/