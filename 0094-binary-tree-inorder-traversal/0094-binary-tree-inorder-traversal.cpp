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
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);    
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
};

/*🌳 Inorder = Left → Root → Right

Using the same tree:

        1
       / \
      2   3
     / \
    4   5

Inorder:

4 → 2 → 5 → 1 → 3
🧠 Think exactly like Preorder

For every node:

If node == NULL → return
Go left recursively
Process current node
Go right recursively

.....................................................................................
*/