class Solution {
public:
    int trap(vector<int>& height) {
        //nt n = nums.size();
        int left = 0;
        int right = height.size()-1;
        int lmax = 0;
        int rmax = 0;
        int water_store = 0;
        while(left<=right)
        {
            if(lmax<=rmax)
            {
                //means water left tak jaega left fix
                lmax = max(lmax,height[left]);
                water_store+=lmax-height[left];
                left++;
            }
            else
            {
                //means water righttak jaega right fix
                rmax = max(rmax,height[right]);
                water_store+=rmax-height[right];
                right--;
            }
        }
        return water_store;
        
    }
};
