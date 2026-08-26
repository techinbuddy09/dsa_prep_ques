class StockSpanner {

    //pair type stck -> {price,index}
    stack<pair<int,int>>st;
    int idx = 0 ;// for the current index
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 0 ;
        //we gonna run a loop and pop all the elements which are <=  as they can never the nge so pop them
        while(!st.empty() && st.top().first <= price)
        {
            st.pop();
        }

        //next suppose after pop if the stack its empty=>no nge
        //if there thats it'
        if(st.empty())
        {
            span = idx+1;
        }
        else
        {
            span = idx - st.top().second;
        }

        // in the end push in stack and update  the index too
        st.push({price,idx});
        idx++;// update the current index too here

        return span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
 

/*
 For every new price:
Count how many consecutive previous days (including today) had price ≤ today's price.

Once we find that greater element's index:
span = current_index - greater_element_index

If there is no greater element:
span = current_index + 1


=>>for each new price:

while stack top <= current price
    pop

Why?

Because if the top price is <= current, it cannot be the greater boundary for current or future relevant prices. So we remove it.

Then:

if stack empty
    span = current_index + 1
else
    span = current_index - stack.top.index

Finally:

push current (price, index)

So the pattern is:

POP smaller/equal
      ↓
stack top = nearest greater on left
      ↓
calculate span
      ↓
push current[ after calculating the span we need to push the current for the next ones]
*/