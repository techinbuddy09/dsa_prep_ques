class Solution {
    typedef long long ll;
    vector<ll>nsl(vector<int>& heights)
    {
     vector<ll>left;
     stack<pair<int,int>>st;
     int idx = -1;
    int n = heights.size();
    for(int i = 0;i<n;i++)
       {
        if(st.size() == 0)
        {
            left.push_back(idx);
        }
        else if(st.size()>0 && st.top().first < heights[i])
        {
            left.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first >= heights[i])
        {
            while(st.size()>0 && st.top().first >= heights[i])
            {
                st.pop();
            }
            if(st.size() == 0)
            {
                left.push_back(idx);
            }
            else
            {
                left.push_back(st.top().second);
            }
        }
        st.push({heights[i],i});
    }
    return left;
}
vector<ll>nsr(vector<int>& heights)
    {
     vector<ll>right;
     stack<pair<int,int>>st;
     int n = heights.size();
     int idx = n;
    for(int i = n-1;i>=0;i--)
       {
        if(st.size() == 0)
        {
            right.push_back(idx);
        }
        else if(st.size()>0 && st.top().first < heights[i])
        {
            right.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first >= heights[i])
        {
            while(st.size()>0 && st.top().first >= heights[i])
            {
                st.pop();
            }
            if(st.size() == 0)
            {
                right.push_back(idx);
            }
            else
            {
                right.push_back(st.top().second);
            }
        }
        st.push({heights[i],i});
    }
    reverse(right.begin(),right.end());
    return right;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n =  heights.size();
        vector<ll>nsl_idx = nsl(heights);
        vector<ll>nsr_idx = nsr(heights); 
        ll max_area = 0;
        // now lets iterate 
        for(int i=0;i<n;i++)
        {
            ll width = nsr_idx[i]-nsl_idx[i]-1;
            ll area  = 1LL*width*heights[i];
            max_area = max(max_area,area);
        }
        return (int)max_area;
    }
};
