class Solution {
public:
    bool isValid(string s) {
        // step one push all the opening unto the stack 
        stack<char>st;
        for(char ch:s)
        {
            if(ch == '{' || ch == '[' || ch == '(')
            {
                st.push(ch);
            }
            else
            {
                //now the case if supppose the charcter we encountered closing to if it doesnt matches st.top() false na also 
                // first check for the stack empty too like closing u have but stack mein koi opening hi na ho
                if(st.empty()) return false;

                //next invalid case condition
                if((ch == ']' && st.top()!='[') || (ch == '}'&& st.top()!='{') || (ch == ')' && st.top()!='('))
                {
                    return false;//means the closing didnt got the corect opening so invalid case
                }

                // if not simply pop from stack
                st.pop();
            }
        }

        //in the end if stack is empty return false
        return st.empty();
    }
};
// here so what we have to do is
// here in this ques every opening parenthesis it has a closing
//opening brackets must closed by same closing omes
//every closing parenthesis has a corresponding open
//the most recent thing needs to be handled first 

