class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> pibo;
        pibo.push_back(1);
        pibo.push_back(1);

        for(int i = 2; i < k + 1; i++) {
            int sum = pibo[i - 1] + pibo[i - 2];
            if(sum > k)
                break;
            pibo.push_back(sum);   
        }

        for(int i = pibo.size() - 1; i >= 0; i--) {
            int temp = k;
            int count = 0;

            if(temp - pibo[i] == 0) {
                return count + 1;
            } else if(temp - pibo[i] > 0) {
                temp -= pibo[i];
                count++;

                for(int j = i - 1; j >= 0; j--) {
                    if(temp - pibo[j] == 0)
                        return count + 1;
                    else if(temp - pibo[j] > 0) {
                        temp -= pibo[j];
                        count++;
                    }
                }
            }
        }
        return -1;
    }
};