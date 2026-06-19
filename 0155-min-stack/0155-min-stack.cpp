class MinStack {
    stack<long long>st;
    long long min_ele =-1;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        //empty stack
        if(st.size() == 0)
        {
            st.push(value);
            min_ele = value;
        }
        else //two cases
        {
            //case 1 >=
            if(value >= min_ele)
            {
                //simply push in stack no need to update the min_Element
                st.push(value);
            }
            //case 2 <
            else if(value < min_ele)
            {
                st.push(2ll*value-min_ele);
                min_ele=value;//update the min_ele too
            }
        }
    }
    
    void pop() {
        //empty stack
        if(st.size() == 0)
        {
            return ;
        }
        else
        {
            //two cases
            //case 1 >=
            if(st.top() >= min_ele)
            {
                //simply pop it
                st.pop();
            }
            //case 2 <
            else if(st.top() < min_ele)
            {
               min_ele = 2*min_ele - st.top();
               st.pop();
            }
        }
        
    }

    int top() {
        // empty stack
        if(st.size() == 0)
        {
            return -1;
        }
        else
        {
            // two cases
            //case 1 >=
            if(st.top() >= min_ele)
            {
                return st.top();
            }
            //case 2 <
            else if(st.top() < min_ele)
            {
                return (int)min_ele;
            }
        }
        // if nothing return -1
        return -1;
    }
    int getMin() {
        //empty stack
        if(st.size() == 0)
        {
            return -1;
        }
        else
            return min_ele;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */