class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1)
            return false;

        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
                st.push(s[i]);
            } else {
                if(st.empty())
                    return false;

                char c = st.top();
                if ((c == '(') && (s[i] == ')'))
                    st.pop();
                else if((c == '{') && (s[i] == '}'))
                    st.pop();
                else if((c == '[') && (s[i] == ']'))
                    st.pop();
                else
                    return false;
            }
        }
        
        if(!st.empty())
            return false;
        return true;
    }
};