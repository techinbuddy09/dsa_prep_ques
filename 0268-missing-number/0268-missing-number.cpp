class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_range = 0;
        int xor_arr = 0;
        for(int i = 0;i<=n;i++)  // here we iterated on the range [0 --- n]
        {
            xor_range^=i;
        }
        for(int no:nums) // here we xor only the elements in the array
        {
            xor_arr^=no;
        }
        return xor_range^xor_arr;
        
    }
};
/*we have to return only the number in the range that is missing
here we are going to learn the xor pattern over here
x ^ x = 0
x ^ 0 = x  => this is the property of xor theek
=>we are basically going to xor of the elements in the array
=>and then the xor of the numbers in the range [0 n]
[3,0,1] => [3^0]=3^1
[0,1,2,3]=>[0^1=1^2^3]=>now next we gonna perform the xor of both

[3^1] ^ [1^2^3]=2 is the ans [since 1^1 = 0 and 3^3 = 0]
=>our misinig number no is 2
// firtly xor of range
// then xor of array elements
// then next we gonna xor [xor_range^xor_elements]heheh
*/