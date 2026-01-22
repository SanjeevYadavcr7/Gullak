class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char &ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') stk.push(ch);
            else {
                if(stk.empty()) return false;
                char top_ch = stk.top();
                if(ch == ')' && top_ch != '(') return false;
                if(ch == '}' && top_ch != '{') return false;
                if(ch == ']' && top_ch != '[') return false;
                stk.pop();
            }
        }
        return stk.size() == 0;
    }
};
