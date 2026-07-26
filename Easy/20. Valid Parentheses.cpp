class Solution {
public:
    bool isValid(string s) {
        stack<char> Parentheses;
        for(int i = 0; i < s.length(); i++){
            if (Parentheses.empty()) {
                Parentheses.push(s[i]);
            }
            else {
                if (Parentheses.top() == '(' && s[i] == ')' || Parentheses.top() == '[' && s[i] == ']' || Parentheses.top() == '{' && s[i] == '}') {
                    Parentheses.pop();
                    continue;
                }
                else {
                    Parentheses.push(s[i]);
                }
            }
        }
        return Parentheses.empty();
    }
};