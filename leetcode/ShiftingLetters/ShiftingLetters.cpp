class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<int> newShifts = shifts;
        newShifts[newShifts.size() - 1] = newShifts[newShifts.size() - 1] % 26;

        for(int i = shifts.size() - 2; i >= 0; i--) {
            newShifts[i] = (newShifts[i] + newShifts[i + 1]) % 26;
        }
        
        for(int i = 0; i < newShifts.size(); i++) {
            s[i] = ((s[i] - 'a' + newShifts[i]) % 26) + 'a';
        }
        
        return s;
    }
};