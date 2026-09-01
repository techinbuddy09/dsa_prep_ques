class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // alright so we gonna do this ques by the optimal one approach which is hashing

        //here we calc the remaiing value of our target and try to locate in hashmap
        //if found return indicies of tha {remaining ele indicies , current_ele indicies}

        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0 ;i<n;i++)
        {
            int rem = target - nums[i];
            // now locate in map if found its good  we return the indicies 
            //if not update the value in map
            if(mp.find(rem)!= mp.end())
            {
                return {mp[rem],i};
            }
            //if not we need to update it
            mp[nums[i]] = i;
        }
        //and if nothing is found ..we  gonna return nothing 
        return {-1};
        
    }
};

// solved the ques using t.c = O(n) ..like the t.c to look for elements in the hash map O(1) best and worst is O(n)