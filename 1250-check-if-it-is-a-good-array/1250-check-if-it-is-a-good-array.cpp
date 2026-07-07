class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for(auto it:nums)
        {
            g = gcd(g,it);
        }
        return g == 1;// if g==1 then return true else false
        
    }
};
// so basically here in this question
// we gonna use bezout's identity
// states for any 2 integers there exsists any integers 
// such that ax+by = gcd(a,b)
//a gcd  we are finding 
//so basically here in this ques we gonna take a subset from array 
// can multiply with any integer and ask can we get 1?
// basically if gcd = (a,b) == 1 then yes we can
// if we got gcd around 4 => its a multiple of 4 =>not good array