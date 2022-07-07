class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        int flag;
        for(int i = 0; i < s.size(); i++)
        {
            if(S.empty())
                S.push(s[i]);
            else if((s[i] == ')' && S.top() == '(') || (s[i] == '}' && S.top() == '{') || (s[i] == ']' && S.top() == '[')){
                S.pop();
            }
            else
                S.push(s[i]);
        }
        if(S.empty())
            return true;
        else
            return false;
    }
};