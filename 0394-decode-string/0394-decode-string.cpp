class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        string curr_str ="";
        int curr_no = 0;
        for(char ch:s)
        {
            if(isdigit(ch))
            {
                curr_no = curr_no*10 + (ch-'0');// we have to multiply over here
            }
            else if(ch == '[')
            {
                st.push({curr_str,curr_no});
                curr_str = "";
                curr_no = 0;
            }
            else if(ch == ']')
            {
                string rep_str ="";
                auto it = st.top();
                st.pop();
                int prev_no = it.second;
                string prev_str = it.first;
                while(prev_no--)
                {
                    rep_str+=curr_str;
                }
                //update the curr_str
                curr_str = prev_str+rep_str;
            }
            else
            {
                curr_str+=ch;
            }
        }
        return curr_str;
    }
};