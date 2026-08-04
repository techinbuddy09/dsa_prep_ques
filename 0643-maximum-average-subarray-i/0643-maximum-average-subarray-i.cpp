class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        //the return type of our ans is double
        //firstly we will create our first window

        for(int i =0;i<k;i++)
        {
            sum+=nums[i];
        }
        //next we will calculate the avg
        double avg = double(sum)/k;

        //now next after the first window now we gonna slide
        for(int i = k;i<n;i++)
        {
            //firstly add the element which is on right
            sum+=nums[i];
            //secondly  we remove the element which is k positions behind
            sum-=nums[i-k];
            //next we gonna calculate maximum avg of the subarray
            avg =  max(avg,double(sum)/k);
        }
        return avg;
        
    }
};

