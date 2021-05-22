class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;

        string temp = "";
        temp += s[0];
        int ret = 0;

        for(int i = 1; i < s.size(); i++) {
            bool isFind = false;
            int findIdx = 0;
            for(int j = 0; j < temp.size(); j++) {
                if(temp[j] == s[i]) {
                    isFind = true;
                    findIdx = j + 1;
                    break;
                }
            }

            if(isFind) {
                int size = temp.size();
                ret = max(ret, size);
                temp = temp.substr(findIdx);
                temp += s[i];
            } else {
                temp += s[i];
            }
        }
        
        int tempSize = temp.size();
        return max(ret, tempSize);
    }
};