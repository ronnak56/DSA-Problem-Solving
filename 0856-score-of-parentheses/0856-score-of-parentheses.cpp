class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);  // initial score

        for (char c : s) {
            if (c == '(') {
                st.push(0);  // new frame
            } else {
                int top = st.top(); st.pop();
                int val = (top == 0) ? 1 : 2 * top;
                st.top() += val;  // add to previous frame
            }
        }

        return st.top();
    }
};