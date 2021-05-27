class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int n = strs.size();
        for(int i = 0; i < strs[0].length(); i++){
            for(int j = 1; j < n; j++){
                if(strs[j - 1][i] > strs[j][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};