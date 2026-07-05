class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss (path);
        stack<string>st;
        while(getline(ss,token,'/'))
        {
            if(token == "." || token == "")
            {
                continue;// dont do anything
            }
            if(token != "..")
            {
                st.push(token);
            }
            else if(!st.empty())
            {
                st.pop();// if not empty then pop
            }
        }
        //edge case if stack empty return root directory
        if(st.empty())
        {
            return "/";
        }
        string rev ="";
        while(!st.empty())
        {
            rev="/"+st.top()+rev;
            st.pop();
        }
        return rev;
    }
};