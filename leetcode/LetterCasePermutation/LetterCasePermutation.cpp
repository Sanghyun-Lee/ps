class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        ans.push_back(s);

        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= '0') && (s[i] <= '9'))
                continue;

            int size = ans.size();
            for(int j = 0; j < size; j++) {
                string temp = ans[j];  
                if(temp[i] - 'a' >= 0)
                    temp[i] -= 32;
                else
                    temp[i] += 32;
                ans.push_back(temp);
            }
        }

        return ans;
    }
};