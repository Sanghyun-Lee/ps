class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int c[30] = {0};
        int count = 0;

        for(int i = 0; i < ransomNote.size(); i++) {
            c[ransomNote[i] - 'a']++;
            count++;
        }
        
        for(int i = 0; i < magazine.size(); i++) {
            int idx = magazine[i] - 'a';
            
            if(c[idx] > 0) {
                c[idx]--;
                count--;
            }
        }
        
        if(count > 0)
            return false;
        return true;
    }
};