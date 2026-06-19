class MinStack {
    stack<long long>st;
    long long min_ele = -1;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        //if stack is empty
        if(st.size() == 0)
        {
            st.push(val);
            min_ele = val;
        }
        else
        {
            //case 1 >=
            if(val >= min_ele)
            {
                st.push(val);
            }
            else if(val < min_ele)
            {
                st.push(2ll*val - min_ele);
                min_ele = val;            }
        }
        
    }
    
    void pop() {
        // acse 1 if val >= min_ele
        if(st.top() >= min_ele)
        {
            st.pop();
        }
        else if(st.top() < min_ele)
        {
            min_ele = 2*min_ele - st.top();
            st.pop();
        }    
    }
    
    int top() {
        if(st.size() == 0)
        {
            return -1;// nothing we will have at the top of the stack
        }
     else
    {
        if( st.top() >= min_ele)
        {
            return (int)st.top();//the element we have at the top of the stack
        }
        else if(st.top() < min_ele)
        {
            return (int)min_ele;
        } 
    }  
        return -1; // if nothing  
    }
    
    int getMin() {
        if(st.size() == 0)
        {
            //if we have empty stack then
            return -1;
        }
        return(int) min_ele;//else return the minimum element
        
    }
};
// typecasted the value since converted in long long format

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */