class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++) {
            if(isPrime(countNum(i)))
               count++;
        }
        return count;
    }
    
    int countNum(int n) {
        int count = 0;
        while (n != 0){
            int ret = n % 2 == 1;
            if(ret == 1)
                count++;
            n /= 2;
        }
        return count;
    }
    
    bool isPrime(int n) {
        if(n < 2)
            return false;
        
        int a = (int) sqrt(n);
        for(int i = 2; i <= a; i++)
            if(n % i == 0)
                return false;

	return true;
    }
};