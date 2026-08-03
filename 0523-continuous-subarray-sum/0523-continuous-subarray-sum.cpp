class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int,int>mp;
        //imaginary index
        mp[0] =-1;
        // our hash map is containing [remainder->first index]
        int curr_prefix_sum = 0;
        for(int i = 0;i<n;i++)
        {
            curr_prefix_sum+=nums[i];
            int remainder = curr_prefix_sum%k;

            // next we check if this remainder occured before if yes => yes valid next check len validity
            if(mp.find(remainder)!= mp.end())
            {
                //if this remainder seen before in that case 
                // here we chexk the validity theek means same remainder shows
                // yes subarrays sum divisible by k
                //next length should have atleast 2 numbers
                if(i - mp[remainder] >=2)
                     return true;
            }
            //close the entire if block here
                else
                {
                    // if not and the key doest exists firstly create key with defaukt value
                    // and next update the first index
                    mp[remainder] = i;
                }
            }
        // and if nothing happens
        return false;
    }
};
