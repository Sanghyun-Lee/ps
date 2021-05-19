class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        
        int index = -1;
        for(int i = 0; i < haystack.size(); i++) {
            if(i + needle.size() > haystack.size())
                return index;

            if(haystack[i] == needle[0]) {
                index = i;
                for(int j = 1; j < needle.size(); j++) {
                    if(haystack[i + j] != needle[j]) {
                        index = -1;
                    }
                }
                if(index != -1)
                    return index;
            }
            
        }
        return index;
    }
};