class Solution {

    vector<int>nsl(vector<int>&nums)
    {
        int n  = nums.size();
        vector<int>left;
        stack<pair<int,int>>st;
        int pseudo_idx = -1;
        for(int i = 0;i<n;i++)
        {
        if(st.size() == 0)
        {
        left.push_back(pseudo_idx);
        }
        else if(st.size() > 0 && st.top().first < nums[i])
        {
            left.push_back(st.top().second);
        }
        else if(st.size() > 0 && st.top().first >= nums[i])
        {
            while(st.size() > 0 && st.top().first >= nums[i])
            {
                st.pop();
            }
            if( st.size() == 0)
            {
                left.push_back(pseudo_idx);
            }
            else
            {
                left.push_back(st.top().second);
            }
        }
        st.push({nums[i],i});//push in the stack the value
    }
    return left;
}
    vector<int>nsr(vector<int>&nums)
    {
        vector<int>right;
        int n =nums.size();
        stack<pair<int,int>>st;
        int pseudo_idx = n;
        for(int i = n-1;i>=0;i--)
        {
        if(st.size() == 0)
        {
            right.push_back(pseudo_idx);
        }
        else if(st.size() > 0 && st.top().first < nums[i])
        {
            right.push_back(st.top().second);
        }
        else if(st.size() > 0 && st.top().first >= nums[i])
        {
            while(st.size() > 0 && st.top().first >= nums[i])
            {
                st.pop();
            }
            if( st.size() == 0)
            {
                right.push_back(pseudo_idx);
            }
            else
            {
                right.push_back(st.top().second);
            }
        }
        st.push({nums[i],i});//push in the stack the value
    }
    reverse(right.begin(),right.end());
    return right;
    }
    int MAH(vector<int>&nums)
    {
        int n =nums.size();
        vector<int>nsl_idx = nsl(nums);
        vector<int>nsr_idx = nsr(nums);
        long long max_area  = 0;
        for(int i = 0;i<n;i++)
        {
            int width = abs(nsr_idx[i]-nsl_idx[i])-1;
            long long area = 1LL*nums[i]*width;//calculating the area over here 
            max_area = max(max_area,area);
        } 
        return (int)max_area;//return the max_area of the histogram 
        //did the typecast of the value here for the return type here
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n  =  matrix.size();
        int m = matrix[0].size();
        vector<int>v;
        int max_area = 0;
        // first row traversing
        for(int j = 0;j<m;j++)
        {
            v.push_back(matrix[0][j]-'0');//since char type
        }
        max_area = MAH(v);//calculating the max_area here

        // next we gonna calculate for other histograms too
        for(int i = 1;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(matrix[i][j]!= '0')
                {
                    //we need to convert at every  moment
                    v[j]=(v[j]+ (matrix[i][j]-'0'));
                }
                else
                {
                    //mark it zero
                    v[j]=0;
                }
            }
            //calculate  max area
            max_area =  max(max_area,MAH(v));
        }
        return max_area;
        
    }
};
//here the basic the intuition
// we break or convert our 2d array into the 1d array
// then for each 1d array we calculate the max area of histogram 
// and among all those ma are of histograms we gonna find the maximum and return that area of the histogram