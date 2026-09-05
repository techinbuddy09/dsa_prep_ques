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
    int  check_tree_balance(TreeNode* root) // return type int since we have to return the height na
    {
        //base case
        if(root == NULL)
            return 0 ;

        int lh = check_tree_balance(root->left);
        if(lh == -1)
            return -1;

        int rh = check_tree_balance(root->right);
        if(rh == -1)
            return -1;
        // if all good check tree balance

        if(abs(lh - rh) > 1)
            return -1;
        // if not return height

        return 1+max(lh,rh);            
    }
public:
    bool isBalanced(TreeNode* root) {

        return check_tree_balance(root)!=-1;
    }
};
/* we have to determine here  whether the height od tree is balanced
A binary tree is balanced if, at every node, the height difference between its left and right subtree is at most 1
...................................................................................

| leftHeight - rightHeight | <= 1

...................................................................................

1. Find left height
2. Find right height
3. Check their difference
4. If difference > 1 → UNBALANCED
5. Otherwise return the height

..................................................................................

like if at node 1 ..so usski lh then rh then abs(lh-rh) > 1 => not balanced else yes

...................................................................................

dry run of two cases here :
        1
       / \
      2   3
     /
    4

    so here the dry run it goes like -: like if i am at node 1 .....i go recursively to the left that is node 4

   => then next at node 4 => lh = 0 rh = 0; => 1+max(lh,rh) = 1 return 1
   => node at node 2 we have lh = 1 rh = 0 ..firstly we check balnced tree
   [1-0] = 1<=1 yes balnced so we return the height ..calc height 1+max(lh,rh) = 2

   =>now at node 1 we have lh = 2 and then node 3 we calc so it comes 1 
   theek next calc balncing condition
    |lh - rh | = 2-1 = 1<= 1 =>yes balanced so we can return the height theek
     lets calc height 1+max(lh,rh) = 1+max(2,1) = 3 return  and whole tree is balanced theek 

    .............................................................................

    => but an edge case of unbalnced tree theek like suppose u have 

        1
       /
      2
     /
    4
   /
  5    now here while calculating we go recursively left theek
   => at node 5 - lh = 0 rh = 0 theek => return 1+max(0,0) = 1
   =>next node 4 - lh = 1 rh = 0 theek check balance 1-0 = 1<=1 => yes balanced
   calc ht = 1+max(1,0) = 2
   =>next node 2 - lh = 2 rh = 0 ..check balamce of ree here |2-0| = 2>1 => not balanced => return -1 ..now next at node 1 we see lh == -1 so we return -1 ...like we clearly know here its lst is unbalaced so we dont meed to check further na if lh is -1 only toh aga kyu hi dekhna

   -> so basically if balanced return height
   -> if not return -1 theek
   ...............................................................................
                                                            
 -> l->rh->diff->height return
                  solve(node)
                     ↓
             get left height
                     ↓
              left == -1 ?
               ↙          ↘
             YES           NO
              ↓             ↓
            -1       get right height
                            ↓
                     right == -1 ?
                       ↙       ↘
                     YES        NO
                      ↓          ↓
                    -1       check difference
                                  ↓
                          difference > 1 ?
                           ↙            ↘
                         YES             NO
                          ↓               ↓
                        -1        return height
 ...................................................................................

 checkHeight(root)
       ↓
   ┌───┴────┐
   ↓        ↓
  -1       height
   ↓        ↓
 false     true
 ..................................................................................    

 t.c = O(n)
 s.c = O(h) => till the height of skewed symmetric tree theek

 */
