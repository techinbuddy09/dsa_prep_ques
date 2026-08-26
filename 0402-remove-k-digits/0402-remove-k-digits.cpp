class Solution {
public:
    string removeKdigits(string num, int k) {
        
        // we gonna make our string behave as stacl
        //pop_back,push_back,empty(),back()=>top

        string st;
        // sabse phele greedily remove largest previous digit
        for(char ch:num)
        {
            while(!st.empty() && k>0 && st.back() > ch)
            {
                st.pop_back();
                k--;
            }
            // next push the current 
            st.push_back(ch);
        }

        // may be an edge case if suppose removal lefts
        while(k>0)
        {
            st.pop_back();// remove from back
            k--;
        }

        //next case of leading zeroes
        int i = 0;
        while(i<st.size() && st[i] == '0')
        {
            i++;//move i till 0 seen
        }

        // next substr to start string from i index only
        string res = st.substr(i);

        //if suppose because of string becomes empty
        if(res.empty())
            return "0";// atleast eak toh
        return res;    
    }
};
/* we have to basically return the smallest possible integer after removing k digits from num 
=> while trying to make the number smaller we still need to maintain the order hehe
=>the order remains the same
=>we have to remove the exactly k digits 

-The key is we greedily remove a previous larger digit whenever a smaller current digit arrives, while k > 0

[1432219] theek push 1 in stack next 4 arrives 4>1 =>non pop =>push 4 in stack
next 3 arrives and we check with st.top() where we have 4 > 3 =>pop and k-- =>k = 2 now ..push 3 too
=> stack holding abhi [1,3] and k = 2
now 2 arrives => since 3>2 => pop 3 and k--=>k= 1
and push 2 => stack becomes [1,2] next .....now 2 arrives 
since 2!<2 => no pop simply push 2in stack
=>stack becomes here ->[1,2,2]
..next finally 1 it arrives now st.top() = 2 and current is 1 => 2>1 =>pop the previous last digit greedily and then push 1 also k-- =>k =0 =>we cant pop any 
element now

next we have 9 though 9 > 1  but since k == 0 => we cant pop right so simply push it in array theek

=>our final stack it becomes [1219] hehe our ans 
=>we can pop only k times..if k is over in that we push the current element


YESSSS 😭🔥 **exactly**, you've got both edge cases.

### Edge case 1 — `k` still remains

If the number is already increasing:

```text
12345
k = 2
```

Our greedy condition:

```cpp
st.top() > current
```

never becomes true.

So after traversal:

```text
stack = [1,2,3,4,5]
k = 2
```

We **must still remove 2 digits**.

Since the number is increasing, remove from the **back**:

```text
12345 → 1234 → 123
```

✅ Answer = `123`.

---

### Edge case 2 — Leading zero

Exactly your example:

```text
num = 10200
k = 1
```

Process:

```text
1
```

then `0` arrives:

```text
1 > 0
```

So pop `1`:

```text
stack = [0]
k = 0
```

Then remaining digits:

```text
0 0
```

So constructed result is:

```text
0200
```

But numerically:

```text
0200 = 200
```

Therefore remove leading zeroes:

```text
0200 → 200
```

🔥 **One subtle thing:** don't think of this as another digit removal from `k`. We've already removed exactly `k` digits. We're simply **formatting the resulting number without leading zeroes**.

So the complete mental model is:

```text
Traverse digits
      ↓
while k > 0 && top > current
      ↓
pop + k--
      ↓
push current
      ↓
if k > 0
    remove from BACK
      ↓
remove LEADING ZEROES
      ↓
answer
```

That's the whole **Remove K Digits** pattern. 😎🔥

////////////////////////////////////////////////////////////////////////

After our greedy process, maan lo:

st = "0200";

We want:

"200"

So:

int i = 0;


while(i < st.size() && st[i] == '0')
{
    i++;
}
Dry run

Initially:

st = "0200"
     ↑
     i = 0

st[0] == '0' ✅

So:

i = 1

Now:

st = "0200"
      ↑
      i = 1

st[1] == '2' ❌

So loop stops.

Now:

string ans = st.substr(i);

means:

String ke index i se lekar end tak ka portion le lo.

So:

st      = 0 2 0 0
index     0 1 2 3
              ↑
              i = 1

Therefore:

st.substr(1)
= "200"

Done. 😎

Why substr(i)?

Because we don't actually need to modify the stack/string.

We simply find:

first non-zero digit

and take everything from there.

What if everything is zero?

Example:

st = "000"

Then:

i = 3

because all three zeroes get skipped.

Then:

string ans = st.substr(3);

gives:

""

So:

if(ans.empty())
    return "0";

Hence:

"000" → "0"

🔥 That's all the leading-zero logic is doing.
*/