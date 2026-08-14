class MedianFinder {
    // here in this ques we are going to have basically two heaps 
    //one will be our  maxheap and other will be minheap
    priority_queue<int>left_max;
    priority_queue<int,vector<int>,greater<int>>right_min;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // lets firstly add the number in the heap
        if(left_max.empty()||num<=left_max.top())
        {
            left_max.push(num);
        }
        else
        {
            right_min.push(num);
        }

        // next after inserting we also need to maintain balance
        if(left_max.size() > right_min.size()+1)
        {
            //means left has two extra elements
            right_min.push(left_max.top());
            left_max.pop();
        }

        if(right_min.size() > left_max.size())
        {
            left_max.push(right_min.top());
            right_min.pop();
        }
        // alright so done with balancing
        
    }
    
    double findMedian() {

        if(left_max.size() == right_min.size())
        {
            return((left_max.top()+right_min.top())/2.0);
        }
        else
            return left_max.top();
        
    }
};

