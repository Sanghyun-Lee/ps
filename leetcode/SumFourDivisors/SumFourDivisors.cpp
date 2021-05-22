class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        vector<int> ret;

        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int sum = 1 + n;
            int count = 0;

            int left = 1;
            int right = n;
            int div = 2;
            
            while ((left < right) && (count < 3)) {
                if(n % div == 0) {
                    if(div == n / div) {
                        count++;
                        break;
                    } else {
                        left = div;
                        right = n / div;
                        count += 2;

                        if(count < 3)
                            sum = sum + left + right;
                    }
                }
                div++;
            }
            
            if((left >= right) && (count == 4))
                ret.push_back(sum);
                
        }          

        int sum = 0;
        for(int i = 0; i < ret.size(); i++) {
            sum += ret[i];
        }

        return sum;
    }
};