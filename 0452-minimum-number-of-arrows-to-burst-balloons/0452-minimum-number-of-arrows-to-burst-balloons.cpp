class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows = 1;
        int n = points.size();
        sort(points.begin(),points.end());
        int prevstart = points[0][0];
        int prevend = points[0][1];
        for(int i =1;i<n;i++)
        {
            if(points[i][0] <= prevend)
            {
                // if this condition satisfy
                prevstart = max(prevstart,points[i][0]);
                prevend = min(prevend,points[i][1]);
            }
            else
            {
                arrows++;
                prevstart = points[i][0];
                prevend = points[i][1];
            }
        }
        return arrows;

        
    }
};
//here we have to try out in finding out the common point of intersection between the two intervals
//firstly we gonna sort the intervals on start
// next we will take our first interval as the common region
//next we check foroverlap 
// if overlap=>we need to shrink the common region and min of 1 arrow only used in common region
// if suppose no overlap=>there a gap exists 
// we will shoot a arrow and next our current interval becomes our new common region
//initially we will keep arrow 1 na like one arrow will toh required na for bursting first balloon

