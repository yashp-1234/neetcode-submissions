class MinStack {
public:
    stack<long> st;
    stack<long> minst;

    MinStack() {
        
    }
    
    void push(long val) {
        st.push(val);
        val = min(val, minst.empty() ? val : minst.top());
        minst.push(val);
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
