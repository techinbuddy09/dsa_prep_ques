class Solution {
public:
    int countSubstrings(string s) {
        int count  = 0;
        int n = s.size();
        for(int i =0;i<n;i++)
        {
            //firstly the case of odd length center
            int l =i;
            int r = i;
            while(l>=0 && r<n && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }

            //now the case arises for the even length center
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }
        }
         return count;
        
    }
};
