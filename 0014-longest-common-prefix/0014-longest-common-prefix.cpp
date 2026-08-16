class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";
        // first string take as the refernce
        for(int i = 0;i<strs[0].length();i++)
        {
            // now lets take one one ch and comapare
            char ch = strs[0][i];

            //now lets compare with every other string
            for(int j = 1;j<strs.size();j++)
            {
                // gonna iteate on all the strings leaving refernce
                if(i>=strs[j].length() || strs[j][i]!=strs[0][i])
                {
                    return ans;//break there only
                }
            }

            //else yes so add in ans
            ans+=ch;
        }
        return ans;
        
    }
};
