class Solution {
public:
    int characterReplacement(string s, int k) {
     int  n = s.size();
     int left  = 0;// for the left boundary
     int max_freq = 0;//to store the max frequency
     int ans  = 0;
     unordered_map<char,int>mp;
     // firstly we gonna create the window
     //need to expand the window
     //so move on right
     for(int right = 0;right<n;right++)
     {
        mp[s[right]]++;//enter the element from right

        //next store and update the max frequency
        max_freq = max(max_freq,mp[s[right]]);

        //next invalid window
        while((right-left+1)-max_freq > k)
        {
            mp[s[left]]--;//shrink the window
            left++;//move the left pointer
        }

        //next update the ans
        ans = max(ans,right-left+1);
     }
     return ans;
    }
};
