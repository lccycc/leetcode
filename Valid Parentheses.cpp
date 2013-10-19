class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (unsigned i = 0; i<s.size(); i++){
            if (s[i] == ')'){
                if (sta.size() && sta.top() == '('){
                    sta.pop();
                }else{
                    return false;
                }
            }else
            if (s[i] == ']'){
                if (sta.size() && sta.top() == '['){
                    sta.pop();
                }else{
                    return false;
                }
            }else
            if (s[i] == '}'){
                if (sta.size() && sta.top() == '{'){
                    sta.pop();
                }else{
                    return false;
                }
            }else{
                sta.push(s[i]);
            }
        }
        return sta.empty();
    }
};
