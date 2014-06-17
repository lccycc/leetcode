class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i<s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else{
                if (stk.size() == 0) return false;
                char tp = stk.top();
                stk.pop();
                if (tp=='(' && s[i] != ')' || tp == '[' && s[i] != ']' || tp == '{' && s[i] != '}') return false;
            }
        }
        return stk.size() == 0;
    }
};
