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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);

        bool ltor = true; //set initially at true

        while(!q.empty())
        {
            int n = q.size();
            vector<int>level;
            for(int i = 0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }

            // after each level
            //phele if odd means false ltor so reverse it
            if(!ltor)
            {
                reverse(level.begin(),level.end());
            }
            //next push in queue
            ans.push_back(level);

            //next flip
            ltor = !ltor;
        }   

        return ans;
    }
};
/*# 🌳 Zigzag Level Order Traversal — LC 103

## 1. What is the problem?

We have to traverse the binary tree **level by level**, but the direction alternates at every level.

```text
Level 0 → Left → Right
Level 1 → Right → Left
Level 2 → Left → Right
Level 3 → Right → Left
...
```

Example:

```text
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

Output:

```text
[
    [1],
    [3,2],
    [4,5,6,7]
]
```

---

## 2. Main Idea

Zigzag traversal is basically:

> **Normal Level Order Traversal + alternate reversing of each level**

We still use **BFS + Queue**.

The queue always processes nodes normally from **left → right**.

We only change how the current `level` is stored.

---

## 3. Why Queue?

Since we need:

```text
level by level
```

we use **BFS**.

BFS uses a **Queue** because Queue follows:

```text
FIFO
First In → First Out
```

So:

```text
Root
 ↓
Queue
 ↓
Process node
 ↓
Push left child
 ↓
Push right child
```

---

## 4. How do we alternate direction?

Use a boolean:

```cpp
bool leftToRight = true;
```

If:

```text
leftToRight = true
```

→ keep the level as it is.

If:

```text
leftToRight = false
```

→ reverse the level.

After completing every level:

```cpp
leftToRight = !leftToRight;
```

So:

```text
true
 ↓
false
 ↓
true
 ↓
false
...
```

---

## 5. Level Separation

Just like normal Level Order, we use:

```cpp
int size = q.size();
```

`size` tells us how many nodes belong to the **current level**.

Then:

```cpp
for(int i = 0; i < size; i++)
```

processes exactly those nodes.

---

## 6. Algorithm

```text
1. If root is NULL → return empty answer.

2. Push root into queue.

3. Set:
       leftToRight = true

4. While queue is not empty:

       a. size = queue.size()
       b. Create current level

       c. Process exactly `size` nodes:
              - pop front
              - add value to level
              - push left child
              - push right child

       d. If leftToRight is false:
              reverse(level)

       e. Add level to answer.

       f. Flip leftToRight.

5. Return answer.
```

---

## 7. Code

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

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

            if(!leftToRight)
                reverse(level.begin(), level.end());

            ans.push_back(level);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};
```

---

## 8. Dry Run

Tree:

```text
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

### Level 0

```text
queue = [1]
leftToRight = true
```

Collect:

```text
[1]
```

No reverse.

Flip:

```text
leftToRight = false
```

---

### Level 1

```text
queue = [2,3]
leftToRight = false
```

Collect normally:

```text
[2,3]
```

Reverse:

```text
[3,2]
```

Flip:

```text
leftToRight = true
```

---

### Level 2

```text
queue = [4,5,6,7]
leftToRight = true
```

Collect:

```text
[4,5,6,7]
```

No reverse.

Final:

```text
[
    [1],
    [3,2],
    [4,5,6,7]
]
```

---

## ⭐ Most Important Interview Pattern

```text
Zigzag Level Order
        ↓
       BFS
        ↓
      Queue
        ↓
   q.size() → level
        ↓
 collect normally
        ↓
 alternate reverse
```

### One-line memory trick:

> **Zigzag = Normal Level Order + reverse every alternate level.**

---

## Complexity

### Time: `O(n)`

Every node is processed once.

The reversals across all levels together are also at most `O(n)`.

### Space: `O(n)`

Queue + level/answer storage can take `O(n)` space.

---

## 🔥 Difference from Normal Level Order

### Normal Level Order

```text
[1]
[2,3]
[4,5,6,7]
```

### Zigzag

```text
[1]
[3,2]
[4,5,6,7]
```

**Only the direction of alternate levels changes.**

The BFS/queue mechanism stays the same.
*/