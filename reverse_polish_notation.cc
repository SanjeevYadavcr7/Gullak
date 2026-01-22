class Solution {
public:
    bool isTokenAnOperator(string str) {
        return (str == "+" || str == "-" || str == "*" || str == "/");
    }

    int getTopNum(stack<int>& stk) {
        int num = stk.top();
        stk.pop();
        return num;
    }

    int evalRPN(vector<string>& tokens) {
        int calc_res = 0;
        stack<int> stk;

        for(string token : tokens) {
            if(isTokenAnOperator(token)) {
                int num1 = getTopNum(stk);
                int num2 = getTopNum(stk);
                if(token == "+") calc_res = (num2 + num1);
                else if(token == "-") calc_res = (num2 - num1);
                else if(token == "*") calc_res = (num2 * num1);
                else calc_res = (num2 / num1);

                stk.push(calc_res);
            } else {
                int num = stoi(token);
                stk.push(num);
            }
        }

        return stk.top();
    }
};
