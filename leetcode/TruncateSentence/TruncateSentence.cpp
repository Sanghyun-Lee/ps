class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int count = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                count++;

            if(count < k)
                ans += s[i];

            if(count == k)
                break;
        }
        
        return ans;
    }
};