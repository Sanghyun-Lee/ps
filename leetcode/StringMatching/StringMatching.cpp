class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> results;

        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                string longStr, shortStr;
                if(words[i].size() > words[j].size()) {
                    longStr = words[i];
                    shortStr = words[j];
                } else {
                    longStr = words[j];
                    shortStr = words[i];
                }

                if(longStr.find(shortStr) != string::npos)
                    results.push_back(shortStr);
            }
        }
        
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());
        
        return results;
    }
};