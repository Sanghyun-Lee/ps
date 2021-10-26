class Solution {
public:
    bool isAnagram(string s, string t) {
        int sc[26] = {0};
        int tc[26] = {0};
        
        if(s.size() != t.size())
            return false;
        
        for(int i = 0; i < s.size(); i++) {
            sc[s[i] - 'a']++;
            tc[t[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(sc[i] != tc[i])
                return false;
        }
        return true;
    }
};