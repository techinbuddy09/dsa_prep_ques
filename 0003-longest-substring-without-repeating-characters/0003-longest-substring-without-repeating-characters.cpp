class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //storing the size of the array

        int n = s.size();
        int left = 0;//;eft boundary 
        int ans = 0;
        unordered_map<char,int>mp;
        //now create th window before check so expand the right window
        for(int right =0;right<n;right++)
        {
            //firstl enter charcter in the window
            mp[s[right]]++;

            //next check if invalid window make it valid first 
            while(mp[s[right]]>1)
            {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
        }

        return ans;
    }
};