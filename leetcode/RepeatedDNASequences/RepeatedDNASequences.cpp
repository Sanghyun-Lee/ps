class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_map<string, int> m;

        string dna = s.substr(0, 9);
        for(int i = 9; i < s.size(); i++) {
            dna += s[i];
            if(m.find(dna) == m.end())
                m.insert(pair(dna, 1));
            else
                m[dna]++;
            dna = dna.substr(1, 10);
        }
        
        for(auto m_val : m) {
            if(m_val.second > 1)
                ret.push_back(m_val.first);
        }

        return ret;
    }
};