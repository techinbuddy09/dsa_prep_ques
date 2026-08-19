class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
          // firstly we gonna iterate and thta too on string like andar sare strings ha charcters nahi ha
          stack<int>st;
          for(string  ch:tokens)
          {
            //case-1 check for operators
            if(ch == "+" || ch == "-" || ch == "/" || ch == "*")
            {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if(ch == "+")
                    st.push(a+b);
                else if(ch == "-")
                    st.push(a-b);
                else if(ch == "*")
                    st.push(a*b);
                else 
                    st.push(a/b); 
            }
            else
            {
                //case 2 encountered that its number so firstly convert the string into number and then directly push it in stack
                st.push(stoi(ch));
            }
          }
          return st.top();// it will holding our ans
    }
};
/* here  in this ques  we gonna use stack theek

number → push
operator → pop two values → calculate → push result

4  13  5  /  +
↓  ↓   ↓   ↓
push push push
          ↓
       13 / 5 = 2
          ↓
        push 2
          ↓
        4 + 2
          ↓
          6
alright so the basic intution of the ques it goes like whenever a number is seen we simply push it the stack
=>next whenever a operator is seen we pop the two last push  numbers in stack
=> a = first popped
=> b  = second popped
=>for handling the order we have b(op)a 
=>alright after performing the operation we push the result back in the stack
=> and then repeat the entire process
*/