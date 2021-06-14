class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool isIncreasing = true;
        
        if (arr.size() == 1)
            return false;
        
        if (arr[0] >= arr[1])
            return false;

        for(int i = 2; i < arr.size(); i++) {
            if (isIncreasing) {
                if (arr[i - 1] == arr[i]) {
                    return false;
                } else if(arr[i - 1] > arr[i]) {
                    if (isIncreasing) {
                        isIncreasing = false;
                    }
                }
            } else {
                if (arr[i - 1] <= arr[i])
                    return false;
            }
        }

        if (isIncreasing)
            return false;
        return true;
    }
};