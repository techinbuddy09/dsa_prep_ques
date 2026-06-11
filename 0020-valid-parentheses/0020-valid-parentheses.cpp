class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for( char &ch:s)
        {
            if(st.empty() || ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
                //continue;
            }
            // if not we need to check the character with stack top
            if(ch == ')')
            {
                if(st.top() == '(')
                {
                    st.pop();
                }
                else
                     return false;
            }
            if(ch == ']')
            {
                if(st.top() == '[')
                {
                    st.pop();
                }
                else
                     return false;
            }
            if(ch == '}')
            {
                if(st.top() == '{')
                {
                    st.pop();
                }
                else
                     return false;
            }

        }
        return st.empty();// like if the stack is empty return true 
    }
};
// so basically in order to check for the valid parenthesis firstly if u encounter 
//opening parenthesis push it the stack
// then when u encounter the closing then check that charcter with stack top if same we pop the character from stack if not we return false
// in the end if the stack is empty return true