class MinStack {
public:
    MinStack();
    void push(int val);
    void pop();
    int top();
    int getMin();
private:
    vector<int> st;
    vector<int> min_st;
};

MinStack::MinStack() {}

void MinStack::push(int val) {
    st.push_back(val);
    val = min(val, min_st.size() ? min_st.back() : val);
    min_st.push_back(val);
}

void MinStack::pop() {
    st.pop_back();
    min_st.pop_back();
}

int MinStack::top() {
    return st.back();
}

int MinStack::getMin() {
    return min_st.back();
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */