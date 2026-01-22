class MinStack {
public:
    int min_num = INT_MAX;
    stack<int> main_stk;
    stack<int> min_stk;
    MinStack() {}
    
    void push(int val) {
        min_num = min(min_num, val);
        main_stk.push(val);
        min_stk.push(min_num);
    }
    
    void pop() {
        main_stk.pop();
        min_stk.pop();
        if(min_stk.size() == 0) min_num = INT_MAX;
        else {
            min_num = min_stk.top();
        }
    }
    
    int top() {
        return main_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
