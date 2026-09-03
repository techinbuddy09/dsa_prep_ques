class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n =  nums.size();
        int curmax = nums[0];
        int curmin = nums[0];
        int res = nums[0];

        //start oour iteration from 1st
        for(int i =1;i<n;i++)
        {
            // before starting store the curmax and curmin so we dont loose the access theek
            //also  we maintain curmin and curmax till the current iterated element
            int x = nums[i];
            int prevmax = curmax;
            int prevmin = curmin;

            //now update them
            curmax = max({x,prevmax*x,prevmin*x});
            curmin = min({x,prevmax*x,prevmin*x});
            res = max(res,curmax);
        }
        return res;
    }
};
/*
-here in this ques negative product plays a huge role in maximuizing oyr future product
- here we will look for both two things  1)maximum Product 2)minimum product
.........................................................................................

-If the next number is negative and we want the maximum product, then we multiply it with the minimum product.
.........................................................................................

-If the next number is positive, multiplying it with the minimum will only make it more negative, but multiplying it with the maximum gives a larger positive product.
.......................................................................................

When the next element is positive:

new maximum comes from old maximum
new minimum comes from old minimum

When the next element is negative:

new maximum comes from old minimum
new minimum comes from old maximum

..........................................................................................

Next element -ve → maximum product banane ke liye currMin useful hai, because negative × negative = positive.
Next element +ve → currMax use karna beneficial hai, because positive × positive = bigger positive.
Aur kabhi-kabhi element khud se naya subarray start bhi kar sakta hai, so x bhi candidate hota hai.


..........................................................................................

1. x                 → naya subarray start karo
2. prevMax × x       → previous maximum ko extend karo
3. prevMin × x       → previous minimum ko extend karo
........................................................................................


YESSSS 😭❤️ **Yahi exact confusion tha tumhara!** Ab bilkul sahi pakda.

`currMin` ka role basically ye hai:

> **Aaj ka minimum product kal ke negative number ke saath multiply hoke maximum ban sakta hai.**

Example:

```text
currMax = 6
currMin = -12
next = -4
```

`currMax` se:

```text
6 × -4 = -24 ❌
```

But `currMin` se:

```text
-12 × -4 = 48 🔥
```

Isliye **minimum ko discard nahi kar sakte**.

And haan, ek small refinement:

> Sirf "curMax positive hai aur next negative hai" ke case mein hi nahi — **kisi bhi negative `x` par `currMin` potentially maximum ban sakta hai.**

So final mental model:

```text
currMax → positive maximum ko carry karo
currMin → negative minimum ko carry karo
           ↓
       future negative
           ↓
   negative × negative
           ↓
      BIG MAXIMUM 🔥
```

**Bas yahi Maximum Product Subarray ka soul hai.** 😂❤️

Ab tum isko code karne ke liye ready ho.
*/


