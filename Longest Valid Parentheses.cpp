class Solution {
public:
    /*  stack
        stack is built from the xth character of s, initally to -1
        for each char s[i], if it's a left par (,  push i into stack;
        if ),
            1 stack has only one element, that means, ( is used up. 
                rebuild stack by updating the last one of stack with i
            2 there are more than one element in the stack, 
                pop one, and get valid para string from stack.top()+1 -> i;
                validate the answer with i - stack.top();
    */
            
    int longestValidParentheses(string s) {
        stack<int> p;
        p.push(-1);
        int ans = 0;
        for (int i = 0; i<s.size(); i++){
            if (s[i] == '(') p.push(i);
            else if (p.size() == 1) p.top() = i;
            else{
                p.pop();
                ans = max(ans, i-p.top());
            }
        }
        return ans;
    }
};
