class Solution {
    // pattern used here is expand around the center
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxlen = 1;//atleast eak charcter toh palindromic ho ga hii
        int n = s.size();
        //lets iterate
        for(int i =0;i<n;i++)
        {
            int l = i;
            int r = i;
            //case of odd length center
            while(l>=0 && r<n && s[l] == s[r]) //jabtak ..till then we gonna do the expansion
            {
                if(r-l+1>maxlen)
                {
                    start = l;
                    maxlen = r-l+1 ;
                }
                //next expansion
                l--;
                r++;
            }


            //next the case for the even length center

             l = i;
             r = i+1;
           while( l>=0 && r<n && s[l] == s[r])
           //within boundary checks ha [l>=0 && r<n like within boundaries check we need to do]
           {
                if(r-l+1 > maxlen)
                {
                    start = l;
                    maxlen = r-l+1;
                }
                l--;
                r++;
           }
        }

        // in the end just return the substring
        return s.substr(start,maxlen);
        
    }
};
