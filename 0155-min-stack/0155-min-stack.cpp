class MinStack {
public:
// alright lets define the two stack here
    stack<int>st;//main stack
    stack<int>min_st;//min stack 

    MinStack() {
        
    }
    
    void push(int value) {
       // in min stack ewe push normally
       st.push(value);
       //for the min stack we need to see if empty and <=
       if(min_st.empty() || value <= min_st.top())
            min_st.push(value);
    }
    
    void pop() {
        // before poping we need to store theek
        int x = st.top();
        st.pop();

        //next before pop from min stack we need to compare before poping
        if(x == min_st.top())
            min_st.pop();
    }
    
    int top() {
        return st.top();// return the top of stack top
    }
    
    int getMin() {
        //we have to get the min_element in constant t.c
        return min_st.top();//  solving the get min in constant space t.c
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();

// what makes this ques special is that like here in this ques we need to get the minimum element in constant time that is O(1)
// if suppose first time the min element which we have  at the stack top toh we pop 
// if suppose next time we want min and its not at top =>we cant get the min element in constant time we need to traverse which is not optimized
//=> normal stack cant be used
//how can we remember that minimum element
/*What data structure naturally stores history?

We need:

current minimum
previous minimum
previous previous minimum
... [stack is used]

And when the current minimum is removed, we want to go back to the previous one.

That's again LIFO.

So what can store this history?

=> Another stack.

Therefore:

Stack 1

Stores the actual elements.

Stack 2

Stores the minimum information.

That's the entire core idea.
=>so basically in this ques we gonna use two stacks one for normal op and other to keep the record of the minimum elements

we basically push like in min stack like <= cases bhi in order to handle duplicate ones na

push → always main stack
       <= current min → min stack

pop  → save top first
       pop main
       if saved == min top → pop min

top  → main.top()

getMin → minStack.top()
*/