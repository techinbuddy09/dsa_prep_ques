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
    int helper(TreeNode*root,int &diameter)
    {
        //base case
        if(root == NULL)
            return 0;
        // next recursively calc lst and rst height
        int lh = helper(root->left,diameter);
        int rh = helper(root->right,diameter);
        // next with each recusrive call update the maximum path between two nodes
        diameter = max(diameter,lh+rh);
        return 1+max(lh,rh);    
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int  diameter = 0;
        helper(root,diameter);// with every recursive call u are returning max na
        return diameter;
    }
};