class Solution {
    typedef long long ll;
    vector<ll>nsl(vector<int>&nums)
    {
        vector<ll>left;
        int n = nums.size();
        stack<pair<int ,int>>st;
        int idx =-1;
        for(int i =0;i<n;i++)
        {
            if(st.size() == 0)
            {
                left.push_back(idx);
            }
            else if(st.size()>0 && st.top().first < nums[i])
            {
                left.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first >= nums[i])
            {
                while(st.size()>0 && st.top().first >= nums[i])
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
            st.push({nums[i],i});
        }
        return left;
    }
     vector<ll>nsr(vector<int>&nums)
    {
        vector<ll>right;
        int n = nums.size();
        stack<pair<int ,int>>st;
        int idx =n;
        for(int i =n-1;i>=0;i--)
        {
            if(st.size() == 0)
            {
                right.push_back(idx);
            }
            else if(st.size()>0 && st.top().first < nums[i])
            {
                right.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first >= nums[i])
            {
                while(st.size()>0 && st.top().first >= nums[i])
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
            st.push({nums[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }

    int MAH(vector<int>&nums)
    {
        int n = nums.size();
        vector<long long>nsl_idx = nsl(nums);
        vector<long long>nsr_idx = nsr(nums);
        ll max_area = 0;
        for(int i =0;i<n;i++)
        {
            ll width = abs(nsr_idx[i] - nsl_idx[i])-1;// everythime calculating width
            ll area =  1LL*width*nums[i];//everythime calculating arae
            max_area = max(max_area,area);
        }
        return (int)max_area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>v;
        for(int j = 0;j<m;j++)
        {
            v.push_back(matrix[0][j]-'0');
        }
        int max_area = 0;
        max_area = MAH(v);
        //next lets iterate on others
        for(int i =1;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j]!='0')
                {
                    v[j]=v[j]+matrix[i][j]-'0';
                }
                else
                {
                    v[j]=0;
                }
            }
            // after each 1d we find max mah
            max_area = max(max_area,MAH(v));
        }
        return max_area;
    }
};