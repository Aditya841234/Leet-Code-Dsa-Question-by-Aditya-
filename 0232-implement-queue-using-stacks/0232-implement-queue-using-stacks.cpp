class MyQueue {
//we need two stack one is for inserting and second one is for performing the pop operation 
    stack<int>st2;
    stack<int>st1;
public:
   

    MyQueue() {
        
    }
    //this is perform the push operation in the stack and making it like the queue
    void push(int x) {
        st1.push(x);
    }
    //this code for the pop operation 
    int pop() {
        if(empty()){
            return 0;
        } 
        //if the stack two is not empty so that condition will be perform some operatiomn according to the sitiuation 
        if(!st2.empty()){
           int element = st2.top();
           st2.pop();
           return element;

        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            int element = st2.top();
            st2.pop();
            return element;
        }
    }
    
    //now we are gpoing to write the code for the top of the element the stack 
    int peek() {
        if(empty()){
            return 0;
        }
        //the second stack hold the value that can be become the front value of the queue 
        if(!st2.empty()){
            return st2.top();
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }

            return st2.top();
        }
    }
    
    bool empty() {
      return st1.empty() && st2.empty();  
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