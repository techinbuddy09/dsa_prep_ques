class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;// har price ke liya span ki initial 
     // here in this ques we have been provided with prices  instead of values in the stack
      while(!st.empty() && st.top().first <= price)
      {
          span = span+st.top().second; // like we gonna add the stock prices here
          st.pop();
      }
      // if not simple push 
      st.push({price,span});
      return span;// return the calculated span over here 
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */