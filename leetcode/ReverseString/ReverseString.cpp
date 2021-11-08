class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int l = 0;
        int r = s.size() - 1;
        
        while(l <= r) {
            temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            r--;
            l++;
        }
    }
};