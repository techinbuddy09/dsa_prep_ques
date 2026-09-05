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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //edge case if both null
        if( p == NULL && q == NULL)
            return true;

        //edge case either null

        if(p == NULL || q == NULL)
                return false;

        // if current values differ

        if(p->val != q->val)
                return false;

        //next we check for it recursively

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);              
            
    }
};
/* we have been give the roots of two binary trees here 
   we have to check if they are same or not
   -they are considered same if nodes have same value 

........................................................................................

 Recursive thinking

Suppose we're currently comparing:

p → node 1
q → node 1

First ask:

Are both nodes present?

Then:

Do their values match?

If yes, we recursively compare:

p->left   with   q->left

and

p->right  with   q->right

And both must be same.

..........................................................................................
Our core idea is-:

sameTree(p, q)

       ↓
Are both NULL?
       ↓
    yes → true

Is one NULL?
       ↓
    yes → false

Are values different?
       ↓
    yes → false

Otherwise:
       ↓
compare left subtrees
       +
compare right subtrees
       ↓
BOTH must be true

..........................................................................................

🚨 Important edge cases
Both NULL
p = NULL
q = NULL

Both trees have nothing here → same ✅

One NULL
p = NULL
q = 5

One has a node and the other doesn't → not same ❌

Different values
p = 2
q = 3

→ not same ❌

So at every pair of nodes:

Check current nodes → recursively check left → recursively check right → both must be true.....
........................................................................................

if(p == NULL && q == NULL)
    return true;


if(p == NULL || q == NULL)
    return false;    

 next if  both exists we check if there values equal or not
 if(p->vql!= q->val) 
    return false;

 // and then same we check recursively for left and right theek 

 And if current nodes match, recursively compare both sides:

left subtree same
        &&
right subtree same.... 

retunr sametree(p->l,q->l) && sametree(q->r,q->r)...repeat this process phirsee

........................................................................................

=> so basically our intuition it goes like
check both p &&  for null
then either of it null
next compare current node values
next ..check recursively left && righty for p,q and should return true if both are same ..

.....................................................................................

If even one side returns false, the whole thing becomes false. ❤️
->everything should be same theek
*/