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
    void preorder(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL)
            return;//stop the recusrion

        //else firstly process
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
        return ans;     
    }
};
/*So our exact thought process is:

🌳 Preorder = Root → Left → Right

For every node:

If node is NULL → return ///we stop the recusrion there 
Process the current node → because Root comes first
Recursively go to left
Recursively go to right

.......................................................................................
*/