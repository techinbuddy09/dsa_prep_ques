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
    int maxDepth(TreeNode* root) {
        

        // base case
        if(root == NULL)
             return 0;

        //next we calc left and right height
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1+max(lh,rh);
    }
};
/*The maximum depth = maximum number of nodes from the root down to any leaf.

..................................................................................

We get:

leftDepth ->keft height
rightDepth  ->right height

Then whichever is bigger determines our answer.

So:

max depth of current node
=
1 + max(left subtree depth, right subtree depth)

The +1 is because the current node itself contributes one level.

................................................................................

Maximum depth = height of the binary tree
(when height is counted in number of nodes/levels).

................................................................................

This is a classic bottom-up Tree recursion:

Get information from left + right children → combine it → return to parent.

..............................................................................

## Maximum Depth of Binary Tree — LC 104

### Code

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};
```

### 🧠 Core Pattern

At every node:

```text
left subtree ki depth nikalo
right subtree ki depth nikalo
        ↓
dono mein maximum lo
        ↓
+1 for current node
```

Formula:

```text
maxDepth(root)
=
1 + max(leftDepth, rightDepth)
```

### Base Case

```cpp
if(root == NULL)
    return 0;
```

No node → depth `0`.

### Complexity

* **Time:** `O(n)` — every node is visited once.
* **Space:** `O(h)` — recursion stack, where `h` is tree height.

  * Balanced tree → `O(log n)`
  * Skewed tree → `O(n)`

### ⭐ Interview Pattern

This is a classic **bottom-up Tree recursion**:

> **Get information from left + right children → combine it → return to parent.**


................................................................................

*/