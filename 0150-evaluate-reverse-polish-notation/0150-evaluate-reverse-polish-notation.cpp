class Solution {
    int operate(int a,int b,string tok)
    {
        if(tok == "+")
            return a+b;
        if(tok == "-")
            return a-b;
        if(tok == "*")
            return (long)a*(long)b;
        if(tok == "/")
            return a/b;
        else
            return -1;//like if nothing            
    }
public:
    int evalRPN(vector<string>& tokens) {
        //performing postfix calculations
        stack<int>st;
        for(auto it:tokens)
        {
            if(it == "+" || it == "-" || it == "*" || it == "/")
            {
                // jaise hee we hit an operator we pop the two operands and perform operation
                int b = st.top();//right
                st.pop();
                int a = st.top();
                st.pop();//left;
                int res = operate(a,b,it);
                // after performimg operation we need to push th result back in the stack
                st.push(res);
            }
            else
            {
                // push the elements in stack
                st.push(stoi(it));// convert the string to the integer over here
            }
        }

        return st.top();// the stack top will be holding the answer
    }
};