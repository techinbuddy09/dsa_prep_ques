/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

        void parent_info(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
        {
            if(root == NULL)
                return;//if null break recursion

            parent[root] = NULL;
            queue<TreeNode*>q;
            q.push(root);

            //lets traverse and build the parent treemap
            while(!q.empty())
            {
                TreeNode* root = q.front();
                q.pop();

                if(root->left!= NULL)
                {
                    parent[root->left] = root;//parent[childnode]= parent
                    q.push(root->left);
                }

                if(root->right!=NULL)
                {
                    parent[root->right] = root;
                    q.push(root->right);
                }
            }    
        }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // firstly we gonna make the treemap
        unordered_map<TreeNode*,TreeNode*>parent;
        parent_info(root,parent);

        //next perform bfs from targetnode
        queue<TreeNode*>q;
        vector<int>ans;
        unordered_set<TreeNode*>vis;

        q.push(target);
        vis.insert(target);//start from the target yr
        int dis = 0;

        while(!q.empty())
        {
            int size = q.size();

            //if suppose dis == k

            if(dis == k)
            {
                //push all the nodes at that level in the vecyor
                while(!q.empty())
                {
                    TreeNode* root = q.front();
                    q.pop();
                    ans.push_back(root->val);
                    //q.pop();
                }
                return ans;
            }

            //if not perform bfs in all three possibilities
            for(int i = 0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                // go left

                if(node->left!=NULL && vis.find(node->left) == vis.end())
                {
                    vis.insert(node->left);
                    q.push(node->left);
                }

                //go right

                if(node->right!=NULL && vis.find(node->right) == vis.end())
                {
                    vis.insert(node->right);
                    q.push(node->right);
                }

                //go to the parent

                if(parent[node]!=NULL && vis.find(parent[node]) == vis.end())
                {
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }

            //done with level increase the distance
            dis++;
        }
        return ans;
    }
};

/*
  

  all right so basically we hve to return  the array all those nodes which have a distance of k from the target

  🌳 Problem

Suppose:

        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

Target node:

target = 5

and:

k = 2

Hume woh saare nodes find karne hain jo target 5 se exactly 2 edges/distance away hain.

Target se dekho:

        3
       / \
      5   1
     / \
    6   2
       / \
      7   4

Distance 2 from 5:

5 → 6 = 1
5 → 2 = 1
5 → 3 = 1

Then:

5 → 3 → 1 = 2
5 → 2 → 7 = 2
5 → 2 → 4 = 2
5 → 3 → 1 → actually 0 and 8 are distance 3, so not included.

Therefore answer:

[1, 7, 4]
........................................................................................

🧠 Ab yahan main problem kya hai?

Normal downward tree traversal mein:

parent → child

direction easy hai.

But target 5 se hume upar bhi jaana hai:

      3
      ↑
      5

Aur phir 3 ke doosre subtree mein jaana hai:

        3
       / \
      5   1
          / \
         0   8

So target se distance K find karne ke liye hume tree ko effectively bidirectional banana padega:

child ↔ parent
🔥 Core challenge

Binary tree mein normally node ke paas:

root->left
root->right

..................................................................................

That's the new challenge in this question:

Normal tree:
5 → children

What we need:
5 → parent (3)
5 → children (6,2)

So effectively:

       3
       ↕
       5
      ↙ ↘
     6   2

Once we have that parent connection, the problem becomes much easier: start from 5 and explore left, right, and parent, keeping track of distance.

..................................................................................

now the issue arises how we gonna store the parent information over here :

we gonna make a parent map theek:
Suppose:

        3
       / \
      5   1
     / \
    6   2

For node 5, normally we know:

5 → 6
5 → 2

but we don't know:

5 → 3

because TreeNode doesn't have a parent pointer.

So what do we do?

We traverse the tree once and create a mapping:

parent[5] = 3
parent[1] = 3
parent[6] = 5
parent[2] = 5

Now when we're standing at 5, we know all 3 possible directions:

             3
             ↑
             |
        6 ←  5  → 2

So from 5, we can move:

left → 6
right → 2
parent → 3

 That's the whole reason we're creating the parent map.

Then we'll use BFS starting from target 5.

And one more important thing: when doing BFS, we need a visited set, because otherwise we'd do:

5 → 3 → 5 → 3 → 5 → 3...

and keep going forever. 

So the overall plan is:

1. Create parent map    
        ↓
2. Start BFS from target
        ↓
3. From each node explore:
   left + right + parent
        ↓
4. Track distance
        ↓
5. When distance == k
   collect those nodes

.................................................................................. 
Exactly:

### 1️⃣ Parent map

parent[child] = parent

Taaki har node ke paas effectively 3 possible directions ho:

             parent
                ↑
                |
left ←       node       → right
```

So target se hum **upar bhi ja sakte hain**, jo normal binary tree mein directly possible nahi tha.

---

### 2️⃣ BFS from target

Suppose:

target = 5
k = 2


Start:

distance = 0
queue = [5]


Then:

distance 1:
6, 2, 3

Then:

distance 2:
7, 4, 1


So:

ans = [7, 4, 1]


Exactly as you said:

>Jab distance == k ho → current nodes ko answer mein add kar do.

---

### 3️⃣ `visited` bhi zaroori

Because now our tree has become effectively bidirectional.

From `5`:

5 → 3


But `3` ke paas parent `NULL` nahi, uska child `5` hai.

Without visited:

5 → 3 → 5 → 3 → 5...



So:

visited[node] = true


helps us avoid going back to nodes we've already explored.


## Final intuition

**Parent Map → BFS from Target → explore Left + Right + Parent → track Distance → distance == K → add to answer.**

...................................................................................

Parent Map:-

Tree:

        3
       / \
      5   1
     / \
    6   2

Hum root se start karenge.

At 3

Root ka parent koi nahi hai:

parent[3] = NULL

Ab 3 ka left child 5 hai, toh:

parent[5] = 3

Aur right child 1:

parent[1] = 3

Then 5 par jaate hain:

parent[6] = 5
parent[2] = 5

So final map:

parent[3] = NULL
parent[5] = 3
parent[1] = 3
parent[6] = 5
parent[2] = 5

Bas ek simple rule

Jab bhi hum kisi node ke child ko encounter karein:

parent[child] = currentNode;

For example:

current = 5
child = 6

parent[6] = 5

............................................................................................

DRY RUN:-

Tree:

        3
       / \
      5   1
     / \
    6   2

target = 5
k = 2

Parent map already hai:

parent[5] = 3
parent[3] = NULL
parent[6] = 5
parent[2] = 5
parent[1] = 3
Step 1 — Start BFS from target

Target = 5.

queue = [5]
distance = 0

And:

visited[5] = true

Why visited?

Because ab hum parent direction bhi explore kar rahe hain.

Step 2 — Process node 5

Current:

current = 5
distance = 0

From 5, we have 3 possible directions:

       3  ← parent
       ↑
       5
      / \
     6   2

So:

left = 6
right = 2
parent = 3

All are unvisited.

Queue becomes:

queue = [6, 2, 3]

And now these nodes are at:

distance = 1

So:

5 → 6 = 1
5 → 2 = 1
5 → 3 = 1
Step 3 — Distance 2

Now process the nodes at distance 1.

From 6

6 has no children.

Parent:

parent[6] = 5

But 5 is already visited.

So nothing new.

From 2

Same:

parent[2] = 5

Already visited.

From 3

This is important.

3 has:

left = 5
right = 1
parent = NULL

5 already visited.

But 1 is new.

So:

1 gets distance 2

Now what about k = 2?

We're exactly at distance 2.

So collect the nodes that are at this level.

Depending on the exact tree, here the distance-2 nodes are:

[1]
🎯 Answer
[1]
🔥 The important BFS idea

We don't randomly calculate distance for every node.

We move level by level:

distance 0:
        5

distance 1:
     6   2   3

distance 2:
         1

The moment we reach distance k, we collect that entire level and stop.

And now the whole problem looks like:
1️⃣ Build parent map
       ↓
2️⃣ Start BFS from target
       ↓
3️⃣ From every node:
   left + right + parent
       ↓
4️⃣ visited prevents going backwards forever
       ↓
5️⃣ Move level by level
       ↓
6️⃣ distance == k
       ↓
7️⃣ collect nodes

............................................................................................
*/