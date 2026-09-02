/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        //firstly eak dummy node for head agar it has to be reverse
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

    // edge case
        if(head == NULL || left == right)
                return head;
        ListNode* prev = dummy;
        //sabse phele prev ko left se phele
        for(int i = 1;i<left;i++)
        {
            prev = prev->next;
        }

        //next cur the first node of reverse part
        ListNode* curr = prev->next;
        //next after eak right ke badh to later use for the reconnection of after
        ListNode* after = curr;
        //need to loop here
        for(int i = left ;i<= right;i++)
        {
            after = after->next;
        }

        // this will poistioned at right
        ListNode* end = curr;
        for(int i = left ;i<right;i++)
        {
            end = end->next;
        }

        // here also do the isloation here
        end->next = NULL;
        //now lets reverse
        ListNode* newhead = reverse(curr);

        //next lets do the reconnection
        prev->next = newhead;
        curr->next = after;

        return dummy->next;
        
    }
};
/*Haan yr, **ekdum pura flow** coding se pehle ek baar mind mein set kar lo. 😭

Example:

```text
1 → 2 → 3 → 4 → 5
    ↑       ↑
  left    right
```

We want:

```text
1 → 4 → 3 → 2 → 5
```

### Full flow 🧠

**1. Dummy banao**

```cpp
dummy → 1 → 2 → 3 → 4 → 5
```

Head involved ho sakta hai, isliye dummy.

---

**2. `prev` ko left se one position pehle le jao**

```text
dummy → 1 → 2 → 3 → 4 → 5
         ↑
        prev
```

`prev = 1`

---

**3. `curr` lo**

```cpp
curr = prev->next;
```

So:

```text
1 → 2 → 3 → 4 → 5
↑   ↑
prev curr
```

`curr = 2`

👉 `curr` = reversal portion ka **original first node**.

---

**4. `after` save karo**

Hume pata hai reversal ke baad `2` ko `5` se connect karna padega.

So `after` ko right ke baad le jao:

```text
1 → 2 → 3 → 4 → 5
            ↑   ↑
           right after
```

Loop `left <= right` chalega and finally:

```text
after = 5
```

👉 `after` = **right ke baad wala node**.

---

**5. `end` find karo**

Ab reversal portion ka last node chahiye.

```cpp
end = curr;
```

Then `end` ko right tak le jao.

Finally:

```text
curr                 end   after
 ↓                    ↓      ↓
1 → 2 → 3 → 4 → 5
```

So:

* `curr = 2`
* `end = 4`
* `after = 5`

---

**6. Portion isolate karo**

```cpp
end->next = NULL;
```

Now:

```text
1 → 2 → 3 → 4 → NULL

5
```

So `[left,right]` portion completely separate hai.

---

**7. Normal `reverse()` lagao**

```cpp
newhead = reverse(curr);
```

Because `curr = 2`:

```text
2 → 3 → 4
```

becomes:

```text
4 → 3 → 2
```

Now:

```text
prev       newhead       curr       after
 ↓            ↓            ↓          ↓
1            4 → 3 → 2    2          5
```

Remember: **original `curr` ab reversed portion ka last node hai.**

---

**8. Reconnect**

First:

```cpp
prev->next = newhead;
```

```text
1 → 4 → 3 → 2
```

Then:

```cpp
curr->next = after;
```

```text
1 → 4 → 3 → 2 → 5
```

DONE. ✅😭

### Interview mein pura one-line flow:

> **Dummy → prev before left → curr at left → save after right → find end/right → cut end from after → reverse(curr) → connect prev to newhead → connect curr to after.**

Bas **ye flow yaad**, code automatically aa jayega. 🔥
*/