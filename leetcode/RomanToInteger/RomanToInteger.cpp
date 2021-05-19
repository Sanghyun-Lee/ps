class Solution {
public:
    int romanToInt(string s) {
        map<char, int> rtoi;
        rtoi['I'] = 1;
        rtoi['V'] = 5;
        rtoi['X'] = 10;
        rtoi['L'] = 50;
        rtoi['C'] = 100;
        rtoi['D'] = 500;
        rtoi['M'] = 1000;

        if(s.size() == 0)
            return 0;
        
        if(s.size() == 1)
            return rtoi[s[0]];

        int sum = 0;
        int str_size = s.size();

        for(int i = 0; i < str_size; i++) {
            char c = s[i];
            int next = i + 1;
            
            if((c == 'I') && (next < str_size) && s[next] == 'V') {
                sum += 4;
                i++;
            } else if((c == 'I') && (next < str_size) && s[next] == 'X') {
                sum += 9;
                i++;
            } else if((c == 'X') && (next < str_size) && s[next] == 'L') {
                sum += 40;
                i++;
            } else if((c == 'X') && (next < str_size) && s[next] == 'C') {
                sum += 90;
                i++;
            } else if((c == 'C') && (next < str_size) && s[next] == 'D') {
                sum += 400;
                i++;
            } else if((c == 'C') && (next < str_size) && s[next] == 'M') {
                sum += 900;
                i++;
            } else {
                sum += rtoi[c];
            }
        }
        return sum;
    }
};