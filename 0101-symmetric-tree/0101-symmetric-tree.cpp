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

    bool hell(TreeNode* left ,TreeNode* right)
    {
        if(left == NULL && right == NULL)
                return true;

        if(left == NULL || right == NULL)
                return false;

        if(left->val != right->val)
                return false;

        return hell(left->left,right->right)&&hell(left->right,right->left);                        
    }
    bool isSymmetric(TreeNode* root) {

        // alright so we gonna do this ques in same way as sametree

        if(root == NULL)
            return true;

        return hell(root->left,root->right);    
    }
};
/*symmetric tree :-A tree is symmetric if its left and right sides are mirror images of each other.

Example:

        1
       / \
      2   2
     / \ / \
    3  4 4  3

This is symmetric theek

Look at the corresponding nodes:

left side       right side

   2      ↔        2
  / \             / \
 3   4           4   3

Notice:

left 2 ↔ right 2
left's left 3 ↔ right's right 3
left's right 4 ↔ right's left 4
....................................................................................

here in this Symmetric Tree, we're checking a mirror:

left->left   ↔   right->right
left->right  ↔   right->left  ......should satisfy this 

...................................................................................

Let's imagine we're comparing two nodes

Suppose:

        left        right
          2          2
         / \        / \
        3   4      4   3

We compare:

Current nodes
left->val == right->val

Then:

left->left   ↔ right->right

and:

left->right  ↔ right->left

Both must be true.

....................................................................................

SAME TREE:
left  ↔ left
right ↔ right

SYMMETRIC:
left-left   ↔ right-right
left-right  ↔ right-left

........................................................................

isMirror(left, right)

    ↓

both NULL?
    → true

one NULL?
    → false

values different?
    → false

otherwise:

isMirror(left->left, right->right)
                &&
isMirror(left->right, right->left)
................................................................................

*/