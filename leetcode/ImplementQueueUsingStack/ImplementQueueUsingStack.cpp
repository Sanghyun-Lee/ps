class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.size() == 0) {
            st.push(x);
            return;
        }

        int size = st.size();
        vector<int> temp;

        while(st.size() > 0) {
            temp.push_back(st.top());
            st.pop();
        }

        st.push(x);
        size = temp.size();
        for(int i = size - 1; i >= 0; i--) {
            st.push(temp[i]);
        }
    }
    
    int pop() {
        int ret = st.top();
        st.pop();
        return ret;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {      
        return (st.size() == 0);
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