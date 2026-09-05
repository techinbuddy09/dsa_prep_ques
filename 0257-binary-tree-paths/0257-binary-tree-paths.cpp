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
    void hell(TreeNode* root,vector<int>&path,vector<string>&ans)
    {
        if(root == NULL)
            return;

        //add the current node to the path
        path.push_back(root->val);

        // id suupose rleaf node convert the path to the string
        if(root->left == NULL && root->right == NULL)
        {
            int n = path.size();
            string s = "";
            //lets iterate till path

            for(int i = 0 ;i<n;i++)
            {
                s+=to_string(path[i]);

                //also add "->" leaving last

                if(i!=n-1)
                {
                    s+="->";
                }
            }
            
             ans.push_back(s); // now string s holding the new converted path in string type
             
            //after each path add it 
        }

        //go left and right
        hell(root->left,path,ans);
        hell(root->right,path,ans);

        //next backtrack current node
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>path;
        vector<string>ans;
        hell(root,path,ans);
        return ans;
    }
};
/* alright here in this ques we have to tell all the root to the leaf paths 

Here, we need to return all root-to-leaf paths in the tree.

For example:

        1
       / \
      2   3
       \
        5

The root-to-leaf paths are:

1 → 2 → 5
1 → 3

So output would be:

["1->2->5", "1->3"]

....................................................................................

🧠 Main difference from Path Sum

In Path Sum, we asked:

"Does there exist a root-to-leaf path whose sum equals the target?"

So we carried a remaining target sum.

Here, there is no target sum.

Instead:

We need to collect every root-to-leaf path.

So what do we need to carry while recursively moving down?

👉 The path we've built so far.

For example, starting at 1:

path = [1]

Go left:

path = [1,2]

Go right:

path = [1,2,5]

Now 5 is a leaf.

So we have one complete path:

1->2->5

Then we need to explore the other branch:

1->3

....................................................................................

🔥 The important concept: Backtracking

This question introduces backtracking.

Suppose we're at:

1 → 2 → 5

We've completed this path.

But now we need to go back to 2 and explore another branch (if it exists).

So after processing a subtree, we need to remove the current node from our path.

Conceptually:

add node
   ↓
explore children
   ↓
remove node

This is:

push → recurse → pop

.....................................................................................

🌳 Example
        1
       / \
      2   3
     / \
    4   5

Start:

path = []

At 1:

path = [1]

Go left → 2:

path = [1,2]

Go left → 4:

path = [1,2,4]

4 is leaf → save:

"1->2->4"

Now backtrack:

path = [1,2]

Go right → 5:

path = [1,2,5]

Leaf → save:

"1->2->5"

Backtrack:

path = [1,2]

Done with node 2, backtrack:

path = [1]

Go right → 3:

path = [1,3]

Leaf → save:

"1->3"

Final:

[
    "1->2->4",
    "1->2->5",
    "1->3"
]

...............................................................................

⭐ Core intuition

Keep adding nodes to the current path as you go down. When you reach a leaf, save that path. After finishing a subtree, remove the node to backtrack and explore the next path.

..................................................................................

Suppose we're here:

        1
       / \
      2   3
     / \
    4   5

We go:

1 → 2 → 4

At 4, we've completed one path:

1 → 2 → 4

Now we need to explore the other branch of 2:

1 → 2 → 5

So we have to remove 4 first:

[1,2,4]
     ↓ pop 4
[1,2]
     ↓
add 5
[1,2,5]

Then after finishing 5, we pop 5, finish node 2, and pop 2:

[1,2,5]
     ↓
[1,2]
     ↓
[1]

Then we can explore 3.

🔥 So the exact pattern is:
ADD current node
       ↓
RECURSE into children
       ↓
REMOVE current node

Or the interview shorthand:

Push → Explore → Pop

.................................................................................


1️⃣ node ko path mein PUSH karo

2️⃣ agar leaf hai:
      path ko answer mein daalo

3️⃣ left subtree explore karo

4️⃣ right subtree explore karo

5️⃣ node ko path se POP karo
....................................................................................

*/