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
     void postorder(TreeNode* root,vector<int>&ans)
     {
        if(root == NULL)
            return;

        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val); 
     }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};
/*🌳 Postorder = Left → Right → Root

Same exact recursion pattern. Again, only the position of processing the current node changes.

For:

        1
       / \
      2   3
     / \
    4   5

Postorder:

4 → 5 → 2 → 3 → 1
🧠 Our thought process

For every node:

node == NULL → return
Go left recursively
Go right recursively
Process current node
....................................................................................
*/