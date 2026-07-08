class Solution {
public:
    int calculate(string s) {
      int len = s.length();
      stack<long long>st;
      long no = 0;
      long sign = 1;
      long res  = 0;
      for(int i =0;i<len;i++)
      {
        if(isdigit(s[i])) // if we encounter a digit
        {
            no = no*10+(s[i]-'0');
        }
        else if(s[i] == '+')
        {
            res = (no*sign)+res;
            no = 0;
            sign = 1;
        }
        else if(s[i] == '-')
        {
            res = (no*sign)+res;
            no = 0;
            sign = -1;
        }
        else if(s[i] == '(')
        {
            st.push(res);//pushing the res calc previously
            st.push(sign);
            res = 0;
            sign = 1;
            no = 0;
        }
        else if(s[i] == ')')
        {
            res = (no*sign)+res;
            no = 0;
            sign = 1;
            int  sig = st.top();
            st.pop();
            int num = st.top();
            st.pop();
            res = res*sig;
            res= res+num;
        }
      }
      res = (no*sign)+res; // edge case
      return (int) res;  
    }
};
// here we dont have to use any predefined function
// causing overflow issue so we needed to use long long