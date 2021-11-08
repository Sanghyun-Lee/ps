class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int r = 0;
        int end;
        char temp;
        int size = s.size();
        
        while(l < size) {
            if((s[r] != ' ') && (r < size)) {
                r++;
                end = r;
            } else {
                r--;
                while(l <= r) {
                    temp = s[l];
                    s[l] = s[r];
                    s[r] = temp;
                    r--;
                    l++;
                }
                r = end + 1;
                l = end + 1;
            }
        }
        return s;
    }
};