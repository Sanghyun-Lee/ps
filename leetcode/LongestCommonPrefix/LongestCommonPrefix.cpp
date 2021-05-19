class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";

        int minLen = INT_MAX;
        for(int i = 0; i < strs.size(); i++) {
            if(strs[i].size() < minLen)
                minLen = strs[i].size();
        }
        
        string compareStr = strs[0];
        bool isNotSame = false;
        int prefixIdx = 0;

        for(prefixIdx = 0; prefixIdx < minLen; ++prefixIdx) {
            for(int j = 0; j < strs.size(); j++) {
                if(strs[j][prefixIdx] != compareStr[prefixIdx]) {
                    isNotSame = true;
                    break;
                }
            }
            if(isNotSame)
                break;
        }
        return compareStr.substr(0, prefixIdx);
    }
};