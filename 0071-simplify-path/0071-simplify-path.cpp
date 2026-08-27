class Solution {
public:
    string simplifyPath(string path) {
        
        // firstly creating a stack of strings over here
        stack<string>st;
        stringstream ss(path);
        string copy;//to store the components or peices of strings separated by delimeter
        while(getline(ss,copy,'/'))
        {
            if(copy == "" || copy == ".")
            {
                continue;
            }
            else if(copy == "..")
            {
                //here if the stack is not empty then only pop
                if(!st.empty())
                {
                    st.pop();
                }
            }

            else
            {
                st.push(copy);
            }
        }

        // now in stack we have our components now we need to do the formation 
        string ans ="";
        while(!st.empty())
        {
           ans = "/"+st.top()+ans;
           st.pop();
        }

        // edge case if the string is empty then return the root 

        if(ans  == "")
        {
            return "/";
        }
        return ans;
    }
};
/* okay so our task is to simplify the unix style path into simplified canonical path

=>
normal name → PUSH {simple directory}
"."         → IGNORE {like same directory na}
".."        → POP (like go back to the previous )
""          → IGNORE (agar empty ho toh ignore it)..something like {///}

path
 ↓
split into components
 ↓
normal folder → push
"." → ignore
".." → pop if possible
empty → ignore
 ↓
stack = ["a", "c"]
 ↓
join using "/"
 ↓
"/a/c"
*/