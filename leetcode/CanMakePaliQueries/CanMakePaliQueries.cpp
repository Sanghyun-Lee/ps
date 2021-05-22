class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
       int n = s.length();
        vector<bool> ret;
        vector<vector<int>> ch(n + 1, vector<int>(26, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 26; j++)
                if(s[i - 1] - 'a' == j)
                    ch[i][j] = ch[i - 1][j] + 1;
                else
                    ch[i][j] = ch[i - 1][j];
        }
        
        
        
        for(int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            int k = queries[i][2];
            int count = 0;
            
            for(int j = 0; j < 26; j++) {
                if(ch[right + 1][j] - ch[left][j] & 1)
                    count++;
            }

            ret.push_back(k >= count / 2);
        }

        return ret;
    }
};