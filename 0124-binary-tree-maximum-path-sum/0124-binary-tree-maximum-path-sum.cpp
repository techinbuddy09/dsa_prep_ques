/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans  = INT_MIN;
    int  solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int left = solve(root->left);
        int right  = solve(root->right);

        //to avoid negative contributions and that too conceptually
        int leftgain = max(0,left);
        int rightgain = max(0,right);

        //next we gonna find the max path sum from current node
        int cur_path = root->val + leftgain+rightgain;

        //upadte the maxpath
        ans = max(ans,cur_path);

        //next return the path which node will return to its parent for extending

        return root->val + max(leftgain,rightgain);    
    }
public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
/* 
🌳 Problem

Given:

        1
       / \
      2   3

Possible paths:

2 → 1 → 3

Maximum path sum:

2 + 1 + 3 = 6

So answer = 6.

But ek important cheez:

Path ka matlab hai:

Kisi bhi node se kisi bhi node tak jaa sakte ho, but path continuous hona chahiye.

Aur path root se start hona zaroori nahi hai.

Example:

        -10
        / \
       9   20
          /  \
         15   7

Maximum path:

15 → 20 → 7

Sum:

15 + 20 + 7 = 42

Answer = 42, even though root -10 use hi nahi hua.

.....................................................................................

Sirf ye tree dekho:

        10
       /  \
      5    8

Aur maan lo hume maximum path dhoondhna hai.

Path kya-kya ho sakte hain?
5 → 10

sum = 15

10 → 8

sum = 18

Aur:

5 → 10 → 8

sum = 23 ✅

Toh obvious maximum path hai:

5 → 10 → 8

Ab tak clear? Bas ye samjho.

Ab ek aur important example
        10
       /  \
      5    8

Imagine 10 ke upar ek parent node bhi hai:

          20
           |
          10
         /  \
        5    8

Ab agar 10 ko apne parent 20 ko ek path dena hai, toh kya hum ye path de sakte hain?

20 → 10 → 5
             \
              8

❌ Nahi.

Kyunki path 20 → 10 se neeche aaya, phir 10 se ek hi direction mein ja sakta hai.

So 10 parent ko either:

10 → 5

ya

10 → 8

de sakta hai.

Dono nahi.

Lekin jab hum final answer calculate kar rahe hote hain, tab:

5 → 10 → 8

allowed hai.

❤️ Bas ek sentence yaad karo:

Final path mein node ke dono children use ho sakte hain, but parent ko return karne wale path mein sirf ek child side use kar sakte hain.

....................................................................................


Abhi humne positive values li hain.

What if:

       10
      /  \
    -5    8

Return karte waqt kya hum -5 ko choose karenge?

Obviously nahi 😭

We'll choose:

10 + max(0, -5, 8)

Actually conceptually, negative contribution ko simply ignore karenge.

So:

leftGain  = max(0, left)
rightGain = max(0, right)

Then:

answer through current node:

leftGain + root->val + rightGain

return to parent:

root->val + max(leftGain, rightGain)

And that's basically the complete intuition.

....................................................................................

Tree:

        10
       /  \
     -5    8

Humare paas recursion se:

left  = -5
right = 8

Ab final path banate waqt:

left + 10 + right

karoge toh:

-5 + 10 + 8 = 13

But that's stupid 😭 because `-5` hume **loss** de raha hai.

Better path:

10 → 8

sum = `18`.

So hume har side se decide karna hai:

> **"Kya is side ko path mein include karna beneficial hai?"**

Isliye:
leftGain = max(0, left);
rightGain = max(0, right);

Meaning:

left = -5
max(0,-5) = 0
```

Matlab:

> left side se kuch nahi lenge.

And:

right = 8
max(0,8) = 8
```

Matlab:

> right side se 8 lenge.

Now answer:

0 + 10 + 8 = 18
```

Perfect. ❤️

### But why separate?

Because **left aur right ki values independently decide karni hain.**

Ho sakta hai:

left  = -5
right = 8

→ left reject, right accept.

Ya:

left  = 5
right = -8

→ left accept, right reject.

Ya:

left = -5
right = -8

→ dono reject.

Ya:

left = 5
right = 8

→ dono accept.

So:

leftGain = max(0, left);
rightGain = max(0, right);

**har side ka independent decision hai.**

Bas ek line mein:

> **`max(0, side)` means: "Is side ka contribution positive hai toh le lo, negative hai toh chhod do."** 😭🔥

.................................................................................
Haan yr 😭❤️ **dry run hi karte hain**, because is code ko dry run karne ke baad hi properly lock hoga.

Let's take the simplest useful tree:

```text id="f6h0v1"
        10
       /  \
      5    8
```

We start:

ans = INT_MIN

And call:

solve(10)


### 🔹 Step 1: `solve(10)`

10 NULL nahi hai.

So:
left = solve(5)
right = solve(8)


Pehle **left** jaayenge → `5`. firstly left recursive call

### 🔹 Step 2: `solve(5)`

5 ke children nahi hain.

So:

left = solve(NULL) → 0
right = solve(NULL) → 0


Now:
leftGain = max(0, 0) = 0
rightGain = max(0, 0) = 0

Current path:
0 + 5 + 0 = 5
```

So:

ans = max(INT_MIN, 5)
    = 5
```

Return to parent:

```text id="5nv1ub"
5 + max(0,0)
= 5
```

So **5 returns 5 to node 10**.

---

### 🔹 Step 3: `solve(8)`

Same thing:

```text id="a3q7kn"
left = 0
right = 0

leftGain = 0
rightGain = 0

currentPath = 0 + 8 + 0
             = 8
```

Update:

```text id="4h9z2e"
ans = max(5,8)
    = 8
```

Return:

```text id="6h3x9q"
8 + max(0,0)
= 8
```

So **8 returns 8 to node 10**.

---

### 🔥 Now we're back at node 10

We received:

```text id="n4c8vy"
left = 5
right = 8
```

Now calculate gains:

```text id="r1p7ya"
leftGain = max(0,5) = 5
rightGain = max(0,8) = 8
```

### Current path:

```text id="u6f5dz"
5 + 10 + 8 = 23
```

Update answer:

```text id="e5c7ko"
ans = max(8,23)
    = 23
```

So current best answer is:

```text id="l7p2ab"
5 → 10 → 8
```

### But what does node 10 RETURN?

Remember: parent ke saath path extend karna hai, so **both sides nahi le sakte**.

```text id="y1w8rf"
10 + max(5,8)
= 18
```

So:

```text id="v0x8ma"
return 18
```

Finally `maxPathSum()`:

```text id="3d9q6m"
return ans;
```

Answer:

# 🎯 23

---

### 🧠 Notice the two different numbers:

At node `10`:

```text
currentPath = 23   ← answer ke liye
return = 18        ← parent ke liye
```

**23:** `5 → 10 → 8` — both sides allowed.

**18:** `10 → 8` — only one side because parent ke saath extend karna hai.

Yahi distinction **dry run mein sabse important** hai. ❤️


..............................................................................

solve(-10)
left solve(9)

now root 9  left = null ->returns 0
            right = null -> 0

            lg = max(0,0) = 0
            rg = max(0,0) = 0

            curpath = lg+root->val+rg 
                    = 0+9+0 = 0
            ans = max(int_min,9) = 0

            path return to parent node = root->val + max(lg,rg) = 9+max(0,0) = 9

now from root 10 we go on right solve(20) -> then to its left solve(15)
 root 15  left = null ->returns 0
            right = null -> 0

            lg = max(0,0) = 0
            rg = max(0,0) = 0

            curpath = lg+root->val+rg 
                    = 0+15+0 = 0
            ans = max(9,15) = 15

            path return to parent node = root->val + max(lg,rg) = 15+max(0,0) = 15

now from 20 we go to its right solve(7)

 root 7  left = null ->returns 0
            right = null -> 0

            lg = max(0,0) = 0
            rg = max(0,0) = 0

            curpath = lg+root->val+rg 
                    = 0+7+0 = 0
            ans = max(15,7) = 15

            path return to parent node = root->val + max(lg,rg) = 7+max(0,0) = 7

   now we get back to node 20 
     solve(20)
     root 9  left = 15 
            right = 7

            lg = max(0,15) = 15
            rg = max(0,7) = 7

            curpath = lg+root->val+rg 
                    = 15+20+7 = 42
            ans = max(15,42) = 42

            path return to parent node = root->val + max(lg,rg) = 20+max(15,7) = 35

 now we get back to node -10 
    solve(-10)
     root -10  left = 9 
            right = 35

            lg = max(0,9) = 9
            rg = max(0,35) = 35

            curpath = lg+root->val+rg 
                    = 9+(-10)+35 = 34
            ans = max(42,34) = 42

            path return to parent node = root->val + max(lg,rg) = -10+max(9,35) = 25


            so basically our maximum path sum of continuous sequence is 42                  
            
*/            
                    


