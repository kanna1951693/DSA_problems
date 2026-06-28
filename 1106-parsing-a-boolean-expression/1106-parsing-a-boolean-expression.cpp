class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        
        for (char ch : expression) {
            if (ch == ',') continue;
            if (ch != ')') {
                st.push(ch);
            } else {
                vector<char> operands;
                while (st.top() != '(') {
                    operands.push_back(st.top());
                    st.pop();
                }
                st.pop(); 
                
                char op = st.top();
                st.pop();
                char result;
                if (op == '!') {
                    result = (operands[0] == 't') ? 'f' : 't';
                } else if (op == '&') {
                    bool res = true;
                    for (char c : operands) {
                        if (c == 'f') { res = false; break; }
                    }
                    result = res ? 't' : 'f';
                } else { 
                    bool res = false;
                    for (char c : operands) {
                        if (c == 't') { res = true; break; }
                    }
                    result = res ? 't' : 'f';
                }
                
                st.push(result); 
            }
        }
        return st.top() == 't';
    }
};