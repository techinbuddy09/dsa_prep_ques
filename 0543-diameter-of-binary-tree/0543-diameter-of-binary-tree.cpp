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
     int diameter = 0;

     int helper(TreeNode* root)
     {
        if(root == NULL)
            return 0;

        int lh = helper(root->left);
        int rh = helper(root->right);

        diameter = max(diameter,lh+rh);
        return 1+max(lh ,rh);    
     }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        helper(root);
        return diameter;
    }
};
/* here also we are going to use the same max depth of BT logic + bottom up approach
-> we are to length of the diamter of the tree
->The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root(optional).
.......................................................................................

        1
       / \
      2   3
     / \
    4   5       here we have 4->2->1->3 and length = 3 [ and yes we count the edges theek]
 4->2 = 1,2->1 = 1,1->3 = 1=> 3 edges
.......................................................................................

At every node:

1. Get left height
2. Get right height
3. Calculate path THROUGH current node:
       lh + rh
4. Update global diameter
5. Return height:
       1 + max(lh, rh)
........................................................................................

Notice something beautiful:

The function returns HEIGHT, but while calculating height, we use it to calculate DIAMETER.
.........................................................................................

bruth diamter is basically counting the number of edges ..theek and the current node its not an edge => we will not take that in consideration => diameter = lh+rh
......................................................................................

You nailed the important thing:

### Height vs Diameter

**Height:**

1 + max(lh, rh)

Why `+1`?

Because we're counting the **current node** as part of the height.

**Diameter through current node:**

lh + rh

Why no `+1`?

Because diameter is counting **edges**, and the current node isn't an edge.

---

And your dry run is correct:

        1
       / \
      2   3
     / \
    4   5


### Node 4

```text
lh = 0
rh = 0

diameter = 0 + 0 = 0
height   = 1 + max(0,0) = 1
```

Returns height `1`.

### Node 5

Same:

```text
diameter = 0
height = 1
```

### Node 2

Gets:

```text
lh = 1
rh = 1
```

Path through `2`:

```text
4 → 2 → 5
```

Edges:

```text
4 → 2 = 1
2 → 5 = 1

total = 2
```

Therefore:

```text
diameter = lh + rh
         = 1 + 1
         = 2
```

And height of node 2:

```text
1 + max(1,1)
= 2
```

🔥 **Exactly.**

And then we continue upward.

---

### One tiny correction in what you said

You said:

> "`1 + lh + rh` is basically the height of the tree"

Not quite. 😭

`1 + lh + rh` is **neither the general height nor the diameter**.

The two formulas are:

```text
HEIGHT:
1 + max(lh, rh)

DIAMETER THROUGH NODE:
lh + rh
```

That's an important distinction to keep clean.

### 🧠 Your mental model should now be:

```text
             node
            /    \
          lh      rh

Height:
1 + max(lh,rh)
      ↑
 current node counts

Diameter through node:
lh + rh
      ↑
current node doesn't count as an edge
```

And then we keep a **global diameter** because the longest path could pass through **any node**, not necessarily the root.

.......................................................................................
*/


