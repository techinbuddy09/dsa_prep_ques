class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num:nums)
        {
            pq.push(num);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
        
    }
};
// so whenever we have to find the kth largest number that means we need to maintain our heap to always conatin all the largest numbers
//>whenever a new elements comes and its the smallest we should try to remove it 
// we need to pop from the pq
//so here we will try to maintain the min heap and always smallest element we will have at the top  so we can pop them so if the size of our heap it exceeds the size k
// so in this way all the smallest elemnts they get pop
// and now at the top of pq we will have the kth largest element
// we will try to maintain a min heap of size k
//priority_queue<int, vector<int>, greater<int>>pq;