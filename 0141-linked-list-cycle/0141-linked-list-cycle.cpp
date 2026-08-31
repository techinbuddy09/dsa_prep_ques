/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head ;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;


              if(slow == fast)
                    return true; // means point of collsion mila toh
        }

       return false; // traversed entire fast didnt reached a nopde which it has traversed before ...pura traversal ho gaya and fast is null =>no cycle
    } 
};
/*## 🔄 Linked List Cycle — Notes

### Problem

Check whether a linked list contains a cycle.

Example:

```text
1 → 2 → 3 → 4
        ↑   ↓
        ← ←
```

Output:

```text
true
```

Normal list:

```text
1 → 2 → 3 → 4 → NULL
```

Output:

```text
false
```

---

### 🧠 Intuition — Slow & Fast Pointers

Use two pointers:

```text
slow → moves 1 step
fast → moves 2 steps
```

Both start at `head`.

```cpp
slow = head;
fast = head;
```

Then:

```cpp
slow = slow->next;
fast = fast->next->next;
```

### Why does it work?

**If there is no cycle:**

`fast` eventually reaches `NULL`.

```text
fast == NULL
```

→ No cycle.

**If there is a cycle:**

Both pointers enter the cycle.

Since `fast` moves faster, it eventually **catches up with `slow`**.

```text
slow == fast
```

→ Cycle exists.

So your intuition:

> **Collision of slow and fast means a cycle exists.**

---

### 🔑 Condition

Because `fast` moves two steps, we need:

```cpp
while (fast != NULL && fast->next != NULL)
```

This makes sure:

```cpp
fast->next->next
```

is safe to access.

---

### Code

```cpp
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}
```

### Complexity

```text
Time  → O(n)
Space → O(1)
```

### ⭐ Interview takeaway

**Linked List Cycle = Floyd's Cycle Detection / Tortoise & Hare**

```text
slow → 1 step
fast → 2 steps

collision → cycle
fast reaches NULL → no cycle
```

**Linked List Cycle ✅ DONE.**
*/
