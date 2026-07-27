class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_price = prices[0];
        int max_profit = 0;
        for(int i=0;i<n;i++)
        {
            int profit = prices[i]-min_price;
            max_profit = max(profit,max_profit);
            min_price = min(min_price,prices[i]);//update the min_price too
        }
        return max_profit;
    }
};
