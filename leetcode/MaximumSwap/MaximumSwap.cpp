class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        string maxStr = str;
        vector<int> nums;
        
        for(int i = 0; i < str.size() - 1; i++) {
            for(int j = i + 1; j < str.size(); j++) {
                string temp = str;
                swap(temp[i], temp[j]);
                if(maxStr < temp)
                    maxStr = temp;
            }
        }

        return stoi(maxStr);
    }
};