class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        //step 1-> extract all the words  from the string 
        string word ="";
        vector<string>words;
        //lets iteate and add
        for(char ch:s)
        {
            //if no space encountered add the characters
            if(ch!=' ')
            {
                word+=ch;
            }
            else
            {
                if(!word.empty())
                {
                    words.push_back(word);
                    word ="";//make it empty again
                }
            }
        }

        // add the last word too
        if(!word.empty())
        {
            words.push_back(word);
        }

        //step-2 we gonna reverse it

        reverse(words.begin(),words.end());

        //step -3 to join them 
        string ans="";
        for(int i =0;i<words.size();i++)
        {
            if(i>0)
                ans+=" ";
            ans+=words[i];   
        }
        return ans;
        
    }
};
