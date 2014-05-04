class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 0) return 0;
        stack<int> s;
        for (string e :tokens){
            if (e[e.size()-1]>='0' && e[e.size()-1] <= '9'){
                int x;
                sscanf(e.c_str(), "%d", &x);
                s.push(x);
            }else{
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                int z;
                if (e[0] == '+'){
                    z = x+y;
                }else if (e[0] == '-'){
                    z = x-y;
                }else if (e[0] == '*'){
                    z = x*y;
                }else{
                    z = x/y;
                }
                s.push(z);
            }
        }
        return s.top();
    }
};
