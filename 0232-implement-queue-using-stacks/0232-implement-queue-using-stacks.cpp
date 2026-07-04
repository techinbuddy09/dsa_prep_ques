class MyQueue {
    stack<int>st1;
    stack<int>st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int temp;
        if(st2.size()!=0)
        {
            temp = st2.top();
            st2.pop();
            return temp;
        }
        else
        {
            while(st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
            //pop from stack 2 as its holding the queue front as stack top here
             temp =  st2.top();
            st2.pop();
        }
         return temp;
        
    }
    
    int peek() {
        if(st2.size()!=0)
        {
            return st2.top();
        }
        else
        {
            while(st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
        
    }
    
    bool empty() {
        return st1.empty()&&st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */