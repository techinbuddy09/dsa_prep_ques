class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = height.size()-1;
        int maxarea = 0;
        while(left < right)
        {
            int width = right - left;
            int ht = min(height[left],height[right]);// since water can rise up to smaller level only
            // start from the maximum possibilty
            int area =  width*ht;
            // update max area too
            maxarea = max(area,maxarea);
            //now move the pointers greedily here hehe 
            //bottle neck ha smaller wala toh usse move karo get rid of it
            //mtlb its like pointers move karne pe width toh decrease hoh ga toh we toh koi toh source we need to find to increase area toh height ki badh lelete ha

            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;// this case also covers the case when both the two pointers they are equal toh we can move the either pointers
            }

        }
        return maxarea;
        
    }
};