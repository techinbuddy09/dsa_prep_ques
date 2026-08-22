class Solution {
/*So now you have both halves:

[  → PUSH (repeat, previousString)


]  → POP → repeat current → merge with previousString
*/
public:
    string decodeString(string s) 
    {
        int num = 0;
        string cur_str ="";

        stack<pair<string,int>>st;

        //lets iterate on each character
        //and then we have broadly 4 cases
        for(char ch:s)
        {
            //case 1 digit
            if(isdigit(ch))
            {
                num = num*10+(ch - '0');
            }

            //if opening ] so push an continue current string
            else if(ch == '[')
            {
                st.push({cur_str,num});

                //next continue with the current string so reset everything
                num  = 0;
                cur_str ="";
            }

            //case 3 if closing => pop
            else if(ch == ']')
            {
                auto[prev_str,num] = st.top();
                st.pop();

                //next firstly repeat the current string the num of times
                // then we gonna merge it
                string res ="";
                for(int i = 0;i<num;i++)
                {
                    res+=cur_str;
                }

                //next lets merge it
                cur_str = prev_str+res;
            }

            //case 4 if normal charcter so simply add it to the string
            else
            {
                cur_str+=ch;
            }
        }
        return cur_str;
    }
};
/*for nomral toh its easy
=>the only issue arises when we have nested brackets...

outer
  ↓
inner
  ↓
resolve inner
  ↓
come back to outer

Example:

3[a2[c]]

Jab hum 2[c] ke andar ja rahe hain, humein yaad rakhna padega ki:

bahar kya tha?
→ repeat = 3
→ bahar already kya string bana chuke the?
→ "a"

So temporarily hum ye information save kar denge.

And because nesting mein:

outer → inner → more inner

and closing:

inner → outer → more outer

=>Har [ pe hum us moment ka (repeat, previous string) save kar rahe hain.


So when we see ]:

Pop the saved (repeat, previousString) → repeat the current string → attach it to the previous string.

Conceptually:

current = previousString + (currentString repeated repeat times)



2️⃣ Digit aaye

Yahan thoda important hai because number multiple digits ka bhi ho sakta hai.

Example:

12[a]

Agar 1 mila:

num = 1

Then 2 mila:

num = 1 * 10 + 2
    = 12

So general rule:

num = num * 10 + (ch - '0');
Why num * 10?

Because we're shifting the existing number one decimal place left.

Example:

1 → 12 → 123
1


1*10 + 2 = 12


12*10 + 3 = 123
*/