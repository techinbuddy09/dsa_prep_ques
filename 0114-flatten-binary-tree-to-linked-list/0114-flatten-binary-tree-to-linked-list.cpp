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
   // Save Right → Flatten Left → Move Left to Right → Left NULL → Find Tail → Attach Saved Right → Flatten Right
public:
    void flatten(TreeNode* root) {
        
        //step 1 if null just return stop recusrion
        if(root ==  NULL)
                return;

        //step -2 save the original rst
        TreeNode* right = root->right;

        //step -3 recursively flatten lst

        flatten(root->left);

        //step 4 connect right to left

        root->right = root->left;

        //make left as NULL

        root->left = NULL;

        //next create a point to go to till the end of root->right
        TreeNode* tail = root;
        while(tail->right!= NULL)
            tail = tail->right;

       tail->right = right;//attach

       //we also need to flatten the rst too kya apat usme bhii node pe we went and we founs aree iski bhi tree
       flatten(right);
    }
};
/* alright so here in ques we gonna start 
=>we have to basically flatten the bt into linked list
=>we need to transform it into right skewed symmetric tree theek
=>the order which we need to maintain is the pre-order traversal

Flatten Binary Tree to Linked List — LC 114

Let's not jump to code.

Suppose:

        1
       / \
      2   5
     / \   \
    3   4   6

We have to transform it into a right-skewed linked list:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
🔥 One very important requirement

The order has to be the tree's preorder traversal:

Root → Left → Right

For our tree:

1 → 2 → 3 → 4 → 5 → 6

And after flattening:

left of every node = NULL
right points to the next node in preorder.
🧠 Main question

How do we rearrange the pointers to get this?

Think about node 1:

        1
       / \
      2   5
     / \
    3   4

After flattening, we want:

1 → 2 → 3 → 4 → 5

So the entire left subtree of 1 needs to come between 1 and its original right subtree 5
......................................................................................


Flattening follows preorder traversal:

Root → Left → Right

For our tree:

        1
       / \
      2   5
     / \
    3   4

Preorder is:

1 → 2 → 3 → 4 → 5

So after flattening:

1
 \
  2
   \
    3
     \
      4
       \
        5

Therefore, node 1 ka right = 2, not 5. 

And notice what happened:
Originally 1->right = 5, but because 2,3,4 have to come before 5 in preorder, we put the entire flattened left subtree between 1 and 5.

So conceptually:

1 → [flattened left subtree] → [original right subtree]

i.e.

1 → 2 → 3 → 4 → 5
......................................................................................

For every node, think:

1. Flatten the left subtree
2. Put that flattened left subtree on the right
3. Take the original right subtree and attach it at the END of that flattened left chain

Example:

        1
       / \
      2   5
     / \
    3   4

After flattening left subtree of 1:

1 → 2 → 3 → 4

And the original right subtree was:

5

So attach it at the end:

1 → 2 → 3 → 4 → 5

And importantly:

1->left = NULL
2->left = NULL
3->left = NULL
...

So yes, your statement is 100% the core intuition:

Original right subtree ko flattened left subtree ke END mein attach karna hai.

......................................................................................

Suppose left subtree flatten hone ke baad:

1
 \
  2
   \
    3
     \
      4

Aur original right subtree 5 hai.

Humein 5 ko 4 ke baad lagana hai.

Toh simple: 1 se right-right karte hue end tak jao:

1 → 2 → 3 → 4
            ↑
           tail

Code mein:

TreeNode* tail = root;

while(tail->right != NULL)
    tail = tail->right;

Ab tail 4 par hai.

Then:

tail->right = originalRight;

So:

1 → 2 → 3 → 4 → 5
Ab poora process ek node ke liye:
original:
        1
       / \
      2   5
     / \
    3   4

Step 1: original right save karo → 5

Step 2: left subtree flatten karo → 2 → 3 → 4

Step 3: 1 ka right = 2

Step 4: 1 ka left = NULL

Step 5: flattened chain ka tail 4 find karo

Step 6: 4->right = 5

.....................................................................................

Tree ye hai:

        1
       / \
      2   5
     / \
    3   4

Hum 1 ko flatten karna chahte hain.

Step 1: 1 ke left mein kya hai?

1 ka left subtree:

    2
   / \
  3   4

Ab hum bolte hain:

"Pehle is 2 wale tree ko flatten karo."

Toh 2 wala tree banega:

2
 \
  3
   \
    4
Step 2: Ab ye flattened left subtree 1 ke saath jodega

Originally:

        1
       / \
      2   5
     / \
    3   4

Left subtree flatten hone ke baad:

1

flattened left:
2 → 3 → 4

original right:
5

Ab preorder chahiye:

1 → 2 → 3 → 4 → 5

Toh 1 ka left hata ke:

1 → 2 → 3 → 4

aur 5 ko 4 ke baad attach kar denge:

1 → 2 → 3 → 4 → 5
Bas recursion ka matlab itna hai:

"Pehle chhote subtree ko flatten karo, phir us flattened subtree ko parent ke saath jodo."

Jaise:

1
↓
"2, tu pehle flatten ho ja"
↓
2 → 3 → 4
↓
"ab main isko 1 ke right mein lagaunga"
↓
1 → 2 → 3 → 4
↓
"ab original right 5 ko end mein lagaunga"
↓
1 → 2 → 3 → 4 → 5

Important: Abhi flatten right wali baat side mein rakho. Pehle ye clear karo ki 1 ke liye hum uske left subtree (2) ko pehle flatten karwa rahe hain. यही recursion hai.
......................................................................................

Tumhari understanding exactly ye hai:

At node 1
        1
       / \
      2   5
     / \
    3   4

1️⃣ Save original right

TreeNode* right = root->right;

So:

right → 5

2️⃣ Flatten left recursively

Hum 2 par jaate hain:

    2
   / \
  3   4

Recursion ke through ye banega:

2 → 3 → 4

3️⃣ Is flattened left ko 1 ke right mein daal do

root->right = root->left;

Ab:

1 → 2 → 3 → 4

4️⃣ 1 ka left NULL

root->left = NULL;

5️⃣ Tail find karo

1 → 2 → 3 → 4
            ↑
           tail
TreeNode* tail = root;

while(tail->right != NULL)
    tail = tail->right;

6️⃣ Original saved right ko tail ke baad attach karo

tail->right = right;

So:

1 → 2 → 3 → 4 → 5

.....................................................................................

We are at node 1
        1
       / \
      2   5
     / \
    3   4

We call:

flatten(1->left);

which means:

flatten(2);

Now we are at node 2.

Node 2
    2
   / \
  3   4

First, flatten(2) says:

"Before I can flatten myself, let me flatten my left subtree."

So:

flatten(2->left);

means:

flatten(3);
Node 3

3 has no children:

3

So flattening 3 basically does nothing.

It is already flattened.

We return to 2.

Now node 2 continues

Its left subtree (3) is already flattened:

3

And its original right was 4, which we saved:

right = 4

Now we put the flattened left on the right:

2 → 3

and make:

2->left = NULL

Then find the tail:

2 → 3
    ↑
   tail

Attach saved right:

2 → 3 → 4

🎉 THIS is what flatten(2) actually does.

So when flatten(2) finishes, the original subtree:

    2
   / \
  3   4

has physically become:

2
 \
  3
   \
    4
THEN we return to node 1

Remember, node 1 was waiting for:

flatten(root->left);

That call has now finished.

So node 1's left subtree has become:

2 → 3 → 4

Then node 1 performs the exact same process:

1 → 2 → 3 → 4

and finally attaches its saved 5:

1 → 2 → 3 → 4 → 5
So recursion is basically doing this 👇
flatten(1)
   ↓
flatten(2)
   ↓
flatten(3)
   ↓
3 is already flat
   ↓
flatten(2) finishes → 2 → 3 → 4
   ↓
back to flatten(1)
   ↓
1 → 2 → 3 → 4
   ↓
attach 5
   ↓
1 → 2 → 3 → 4 → 5

The key: flatten(node) means "iss node ke neeche jo poora tree hai, usko linked-list form mein convert karke do."


.....................................................................................

Ek recursive call jab complete ho jaati hai, toh woh wapas us point par return karti hai jahan se call hui thi.

Yahan:

flatten(root->left);

At node 1, this means:

flatten(1)
   ↓
flatten(2)
      ↓
flatten(3)
      ↓
3 finishes
      ↓
back to 2
      ↓
   2 finishes
      ↓
back to 1


......................................................................................
and we gonna repeat the same process for flattening the right subtree too

flatten(root->right)

*/
