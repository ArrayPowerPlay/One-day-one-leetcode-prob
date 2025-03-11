// problem description: https://leetcode.com/problems/valid-parentheses/
// solution below

class Solution {
public:
    // add opening brackets to stack
    /* if elements of string is closing brackets, 
    check its suitable opening brackets in stack */
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            } else if (st.empty()) {
                return false;
            } else {
                // return the element of the top of 'st'
                char check = st.top();
                // remove the top element
                st.pop();
                if ((check == '{' && s[i] != '}') 
                || (check == '[' && s[i] != ']') 
                || (check == '(' && s[i] != ')')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
