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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
            return false;

         if(root->left ==  NULL && root->right ==NULL)
                return targetSum == root->val;// if yes return true

        // if not means subtract the sum from targetsum as its not leaf node na
        targetSum-=root->val;

        return  hasPathSum(root->left,targetSum) ||  hasPathSum(root->right,targetSum);
       
    }
};

/* Does there exist a root-to-leaf path whose node values add up to targetSum?
=>leaf is a node with no children
..................................................................................Example:

        5
       / \
      4   8
     /   / \
    11  13  4
   /  \       \
  7    2       1

Suppose:

targetSum = 22

There is a path:

5 → 4 → 11 → 2

5 + 4 + 11 + 2 = 22

So answer = true ✅

..................................................................................

We're standing at some node.

We have a targetSum remaining.

Suppose we're at:

5

and target is 22.

We've already used 5, so what remains?

22 - 5 = 17

Then we recursively ask:

"Does the left subtree have a root-to-leaf path that adds up to 17?"

and:

"Does the right subtree have one?"

So at every node, we do:

targetSum = targetSum - root->val

and pass the remaining sum down.
=> so basically from the current targetsum we subtract our root->val ..and carry down the remaining sum

....................................................................................

🚨 But there's one VERY important condition

The question specifically says root-to-leaf path.

That means we can only declare success when we're at a leaf.

A leaf means:

root->left == NULL
AND
root->right == NULL

So suppose we're at leaf 2 and after subtracting its value:

targetSum == 0

Then:

YES → valid path ✅

But if we reach a node with:

targetSum == 0

and it still has children, we cannot immediately return true.

Because we haven't reached a leaf yet.

That's an important interview trap.

.................................................................................

🌳 Let's dry run

Take a simpler tree:

        5
       / \
      4   8
     /
    11
   /
  2

Target:

22

Start at 5:

22 - 5 = 17

Go left → 4:

17 - 4 = 13

Go left → 11:

13 - 11 = 2

Go left → 2:

2 - 2 = 0

Now 2 is a leaf AND remaining sum is 0.

Therefore:

true ✅

....................................................................................

target
  ↓
subtract current node
  ↓
go left OR right
  ↓
reach leaf
  ↓
remaining sum == 0 ? and also need to be leaf node too

....................................................................................

### Path Sum — Intuition

Basically, first we check if the current node is `NULL`. If it is `NULL`, we return `false` because there is no path possible from there.

Next, we check whether we have reached a **leaf node**. Since the question specifically asks for a **root-to-leaf path**, we only check the target sum when we reach a leaf.

At a leaf, if:

targetSum == root->val


then we have found a valid root-to-leaf path, so we return `true`.

Otherwise, if the current node is not a leaf, we subtract its value from the current `targetSum` and carry the **remaining target sum** down to the children. Then we recursively check both the left and right subtrees.

For example:

        5
       / \
      4   8
     /
    2

Suppose `targetSum = 11`.

At node `5`:

11 - 5 = 6

So the remaining target becomes `6`, which we carry to the next level.

At node `4`:

6 - 4 = 2


So now the remaining target is `2`.

Then we move to node `2`. Node `2` is a **leaf**, so now we check:

targetSum == root->val
2 == 2


This is `true`, which means we found the valid root-to-leaf path:

5 → 4 → 2


And:

5 + 4 + 2 = 11

Therefore, we return `true`.

### Core Intuition

> **Keep subtracting the current node's value from the target sum as we move down the tree. When we reach a leaf, check whether the remaining target equals the leaf's value.**

*/


