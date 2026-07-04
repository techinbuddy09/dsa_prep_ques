class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        // push the initial element
        q.push(x);
        // then iterate and perform rotation upon n-1 elements
        for(int i =1;i<q.size();i++)
        {
            q.push(q.front());
            q.pop();
            // we always wants to make the newly pushed element to be at the front
        }

        
    }
    
    int pop() {
        int temp  = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();// top of the stack here where queue is behaving like stack
        
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */