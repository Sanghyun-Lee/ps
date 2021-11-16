class Solution {
public:
    vector<string> tokenize(string s) {
        istringstream ss(s);
        string token;
        vector<string> words;
        
        while(getline(ss, token, ' '))
            words.push_back(token);
        
        return words;
    }

    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        vector<string> words = tokenize(s);

        if(pattern.size() != words.size())
            return false;

        for(int i = 0; i < pattern.size(); i++) {
            if((m1.find(pattern[i]) == m1.end()) && (m2.find(words[i]) == m2.end())) {
                m1.insert({pattern[i], words[i]});
                m2.insert({words[i], pattern[i]});
            } else {
                if(m1[pattern[i]] != words[i])
                    return false;
            }
        }
        return true;
    }
};