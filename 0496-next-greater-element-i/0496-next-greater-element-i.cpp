class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>st;
        unordered_map<int,int>mp;
        int n = nums2.size();
        //lets traverse from right to left
        for(int i = n-1;i>=0 ;i--)
        {
            int x = nums2[i];
            while(!st.empty() && st.top() <= x)
            {
                st.pop();
            }
            //if not then add
            if(st.empty())
                mp[x] = -1;
            else
                mp[x] = st.top();

           //in the ned we need to push the current element too
           st.push(x);         
        }

        //now from nums2 we check for the nge for nums1 as it is the subset
        vector<int>ans;
        for(int x:nums1)
        {
            ans.push_back(mp[x]);
        }
        return ans;
    }
};
/* here basically in this ques nums1 is the subset of nums2
Haan 😭 let's code it now. This is the **standard monotonic-stack + hashmap** solution.

```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> mp;

    // Find NGE for every element of nums2
    for (int i = nums2.size() - 1; i >= 0; i--) {
        int curr = nums2[i];

        while (!st.empty() && st.top() <= curr) {
            st.pop();
        }

        if (st.empty())
            mp[curr] = -1;
        else
            mp[curr] = st.top();

        st.push(curr);
    }

    // Get answers for nums1
    vector<int> ans;

    for (int x : nums1) {
        ans.push_back(mp[x]);
    }

    return ans;
}
```

### Code ↔ intuition

```text
nums2 → right to left
          ↓
remove useless smaller/equal elements
          ↓
top = NGE / empty = -1
          ↓
push current
          ↓
store in hashmap
```

Then:

```cpp
for (int x : nums1)
    ans.push_back(mp[x]);
```

Because `nums1` is a subset of `nums2`, every required answer is already calculated.
we wont calculate the nge element for nums1 as its already the subset of nums2 and the nge of nums2 we have stored it in hashmap ..so we gonna simply retrieve from there


### Complexity

* Processing `nums2`: **O(n)**
* Processing `nums1`: **O(m)**
* Total: **O(n + m)**
* Stack + hashmap: **O(n)**
*/


