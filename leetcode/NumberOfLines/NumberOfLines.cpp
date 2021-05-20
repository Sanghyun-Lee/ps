class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int pixel = 0;
        int line = 0;

        for(int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            pixel += widths[index];
            
            if(pixel > 100) {
                line++;
                pixel = widths[index];
            }
        }
        
        vector<int> output;
        output.push_back(line + 1);
        output.push_back(pixel);

        return output;
    }
};