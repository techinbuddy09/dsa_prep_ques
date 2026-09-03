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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        //base case
        vector<vector<int>>ans;
        if(root == NULL)
              return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();//iterate till q size ..like level wize only
            vector<int>level;//for each level new vector

            for(int i = 0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                //lets check for left and right
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }

            ans.push_back(level);
        }      
        return ans;
    }
};

/*## Level Order Traversal — LeetCode 102

### Approach

We use **BFS (Breadth First Search)** because we need to traverse the tree **level by level**, from left to right.

A **queue** is used because it follows **FIFO**:

> First node inserted → first node processed.

### Steps

1. If root is `NULL`, return an empty answer.
2. Push the root into the queue.
3. While the queue is not empty:

   * Store `q.size()` in `size`.
   * `size` represents the number of nodes in the current level.
   * Process exactly `size` nodes.
   * For every node:

     * Remove it from the front.
     * Add its value to the current level.
     * Push its left child if it exists.
     * Push its right child if it exists.
   * Add the current level to the answer.

### Code

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left != NULL)
                    q.push(node->left);

                if(node->right != NULL)
                    q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
```

### Dry Run

For:

```text
        1
       / \
      2   3
     / \   \
    4   5   6
```

Initially:

```text
q = [1]
```

**Level 1:** `size = 1`

```text
process 1
push 2, 3

level = [1]
q = [2,3]
```

**Level 2:** `size = 2`

```text
process 2 → push 4,5
process 3 → push 6

level = [2,3]
q = [4,5,6]
```

**Level 3:** `size = 3`

```text
process 4
process 5
process 6

level = [4,5,6]
```

Final:

```text
[[1],
 [2,3],
 [4,5,6]]
```

### Complexity

* **Time:** `O(n)` — every node is processed once.
* **Space:** `O(n)` — queue can contain up to `O(n)` nodes, and the answer also stores all nodes.

### ⭐ Interview Pattern to Remember

```text
Level Order
     ↓
    BFS
     ↓
   Queue
     ↓
q.size() = current level's nodes
```

And the core template:

```cpp
while(!q.empty()) {

    int size = q.size();

    for(int i = 0; i < size; i++) {

        // process current node

        // push children
    }
}
```

This `q.size()` level-separation trick is the **main thing to remember**.
*/