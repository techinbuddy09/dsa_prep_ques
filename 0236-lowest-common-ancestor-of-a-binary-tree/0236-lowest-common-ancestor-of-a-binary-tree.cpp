/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //edge case 
        if(root == NULL)
            return NULL;

        //next if root equal to either of p or q

        if(root == p || root == q)
                return root;

        //next we gonna search on left and right

        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);

        //next if both return something => yes we got lca
         if(l != NULL && r != NULL)            
                return root;

         // if only left we have then return left only push the current anser upward

         if(l != NULL)
            return l;

         else    // sirf eak hi case we gonna mention theek
            return r;           
    }
};
/*  
    we have to find the lca of two given nodes in tree

    LCA? - so basically LCA is the lowest or deepest node in the tree which is the ancestor of both

    🌳 Example
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

Suppose:

p = 5
q = 1

We need the lowest/deepest node that is an ancestor of both.

Here:

        3  ← LCA
       / \
      5   1

So answer = 3.

.....................................................................................


Step 2: "Common Ancestor"

Suppose hume:

p = 6
q = 2

chahiye.

Dono ke upar jao:

        3
       /
      5
     / \
    6   2

6 ke ancestors:

6 → 5 → 3

2 ke ancestors:

2 → 5 → 3

Common ancestors hain:

5, 3

Ab question bolta hai Lowest Common Ancestor.

Lowest matlab jo dono ke sabse paas hai.

So:

        3
       /
      5  ← LCA
     / \
    6   2

Answer = 5.   

=> in our ques weare asked to find the common ancestor which is lowest too
=> here lowest basically means the common ancestor which is lowest and deepest too

// basically the one which is more near to both

....................................................................................
Step 3: Toh hum actually dhoondh kya rahe hain?

Bas ye:

Aisa sabse neeche wala node jiske andar p aur q dono ki branches milti hain.

For:

      5
     / \
    6   2

5 ke paas:

      5
     / \
    6   2

6 left mein hai, 2 right mein hai.

Dono yahin split ho rahe hain.

👉 Therefore 5 = LCA.

..................................................................................

**But in the Lowest Common Ancestor problem, the definition allows the node itself to be considered an ancestor.

..................................................................................

Imagine this as a family tree
             3
           /   \
          5     1
         / \
        6   2

Suppose mujhe poocha:

6 aur 2 ka Lowest Common Ancestor kaun hai?

Pehle ancestor ka meaning:

6 ke upar jao:

6 → 5 → 3

2 ke upar jao:

2 → 5 → 3

Ab dono lists mein jo common hai:

6 → 5 → 3
2 → 5 → 3
     ↑
   common

Common ancestors = 5, 3

Lowest matlab jo dono ke sabse paas hai.

Therefore:

        3
       /
      5  ← ANSWER
     / \
    6   2

So LCA = 5.

....................................................................................


Let's write your understanding cleanly:

### 🌳 At every node

First:

if(root == p || root == q)
    return root;

Then search:

left  = solve(root->left)
right = solve(root->right)


Now 4 possibilities:

left != NULL && right != NULL
        ↓
current root = LCA

left == NULL && right == NULL
        ↓
return NULL

left != NULL && right == NULL
        ↓
return left


left == NULL && right != NULL
        ↓
return right

....................................................................................

dry run-:

        3
       / \
      5   1
     / \
    6   2

p = 6
q = 1


At node 5, 6 is its left, while 2 is its right. So after 6 returns, we still check 2, which returns NULL. Then node 5 returns 6 upward.
At node 1, since 1 == q, we return node 1. It's not really "return right"; it's returning the current root (1).

So complete flow:

        3
       / \
      5   1
     / \
    6   2

p = 6
q = 1
At 3
3 != p
3 != q

→ search left and right.

At 5
5 != p
5 != q

→ search left.

At 6
6 == p

→ return 6

Then node 5 checks its right:

2 != p
2 != q

→ returns NULL.

So at 5:

left  = 6
right = NULL

→ return 6 upward.

At 1
1 == q

→ return 1

Back at 3

Now:

left  = 6
right = 1

Both returned something! 🎯

Therefore:

3 = LCA
...................................................................................


> **Left and right both return something → current node is the meeting point → current node is LCA.**

And if only one side returns something, **we don't know yet if it's the LCA**, so we simply pass that result upward.


....................................................................................


          current node
               ↓
        Is it NULL?
        /          \
      yes           no
      ↓             ↓
    NULL       Is it p or q?
                 /      \
               yes       no
                ↓         ↓
             return    search both
             root      subtrees
..................................................................................

Remember our targets:

p = 6
q = 1

At node 2:

2 != 6
2 != 1

So we go further:

       2
      / \
    NULL NULL

Left of 2 → NULL → returns NULL.

Right of 2 → NULL → returns NULL.

So 2 ke paas:

left  = NULL
right = NULL

Therefore node 2 returns NULL.   

alright edge case if both p and q is null so return true 

..................................................................................

if(root == NULL)
    return NULL;

Meaning:

Agar current node exist hi nahi karta, toh NULL return karo.

Then next check:

if(root == p || root == q)
    return root;

Meaning:

Agar current node p ya q hai, toh current node return karo.


...................................................................................

1. root NULL?
      ↓ yes → NULL

2. root == p/q?
      ↓ yes → root

3. Search LEFT
4. Search RIGHT

5. Both NULL?
      → NULL

6. Only LEFT?
      → LEFT

7. Only RIGHT?
      → RIGHT

8. Both found?
      → ROOT = LCA

*/      