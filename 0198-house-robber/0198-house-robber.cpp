class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        //base case 
        if(n == 1)
            return nums[0];

        vector<int>dp(n);

        dp[0] = nums[0];
        dp[1]= max(nums[0],nums[1]);
        //from here ownwards we have choices

        for(int i = 2;i<n;i++)
        {
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }    

        //in the end max we have at the last
        return dp[n-1];
        
    }
};
/*dp[i] = maximum money we can rob from houses 0 to i.

So:

dp[0] → max money from house [0
dp[1] → max money from houses[0,1
dp[2] → max money from houses [0,1,2
etc.

...............................................................................

so basically har house pe bas ye pooch rahe hain:

"Is ghar ko lootna better hai, ya isko chhod ke previous houses ka best answer lena?"
...............................................................................

Because dp[i-1] already represents the best possible amount, regardless of which houses we actually robbed.
....................................................................................

At house i, we have two choices:

1️⃣ Don't rob house i

Then we simply take the best answer we had till the previous house:

dp[i-1]

2️⃣ Rob house i

Then we cannot rob house i-1.

So we go to i-2 and take the best possible amount from there, then add the current house's money:

dp[i-2] + nums[i]

Therefore:

dp[i] = max(
    dp[i-1],              // don't rob current
    dp[i-2] + nums[i]     // rob current
)

dp[i] = maximum money we can rob from houses 0 → i.

So dp[i-1] isn't "money from the houses we robbed"; it's the maximum possible money from houses 0 → i-1.

..................................................................................

So remember this distinction:
dp[i] → max money from 0 → i
dp[i-1] → max money from 0 → i-1
dp[i-2] → max money from 0 → i-2

And that's why dp[i-2] is safe when we rob current house — because it automatically excludes the adjacent house i-1.

.................................................................................

acha means maximum possible amount robbed will be the one which we get after we have gone through all the houses na? like here in this ques we have [2,7,9,3,1] theek so like here at first base case hit => dp[0] = 2 only ..then next dp[1] will be max of (2,7) which will be 7 theek ..now from dp[2] ownwards we can have two choices theek like here at dp [2] ist choice rob current => nums[i]+max possible amount robbed till 0 to i-2 theek like skip the adjacnet theek => 9+2 = 11 and doosra dont rob the current and take the maximum possible money robbed till 0 to i-1 means previous that is 7 so max of (7,11) = 11 =>dp[2] = 11 next we are at dp[3] here also same two choices theek that is rob current => nums[i]+dp[i-2] now here i = 3 => 3+dp[3-2]=>3+dp[1]=>3+7=10 and the second case we have dont rob current and take maximum possible amount of money robbed till i-1 theek =>3-1 =>dp[2] tak which is 11 now max(10,11) => 11 ..now next for dp[4] here also same two cases theek eak rob this only => 1+dp[4-2]=>1+11 = 12 and if not => dp[i-1]=>dp[3] = 11 =>max(10,12)=> 12 => return n-1 here dry run 

....................................................................................

At every house:
        /\
       /  \
    ROB    DON'T ROB
     |          |
nums[i]      dp[i-1]
 +           
dp[i-2]

................................................................................

// base case we have 
 if(n == 1) return nums[0] simple wahi hoh ga na

 then dp[0] = nums[0]
      dp[1] = max(nums[0],nums[1])

      //and from 2 owards we have  2 choices and usme se max theek

..and after performing robbing on all the houses we get our maximum possible amount of money we were able to rob .. so return dp[n-1]

=>here dp array basically hold kitna max amount of possible amt of money we have robbed like 0 se i
...............................................................................
*/