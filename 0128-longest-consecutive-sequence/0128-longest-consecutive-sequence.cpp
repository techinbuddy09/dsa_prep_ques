class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n == 0)
            return 0;//base case return 0 if no elements 
        unordered_set<int>st;
        int longest=1;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]); //insert elemnts from nums array to the set
        }    
        //reiterate in set
        for(auto it:st)
        {
            //firstly see if ele not in set
            if(st.find(it-1) == st.end())
            {
                int count=1;
                int x=it;//store the current element
                // now next agin loop till the cinsecutive of that element
                while(st.find(x+1)!= st.end())
                {
                    x=x+1;
                    count=count+1;
                }    
                //here only calculate the longes consecutive sequence
                longest=max(longest,count);                         
            }
        }
        return longest;//return the longest consecutive sequence 
    }
};
//basically in this using  the set data structured the unordered one