class Solution {
public:
    int reverse(int x) {
        if((x < INT_MIN) || (x > INT_MAX))
            return 0;

        long temp = abs(x);
        long output = 0;
        int count = 0;
        
        while(temp) {
            output = output * 10 + temp % 10;
            temp /= 10;
            count++;
        }

        if(output > INT_MAX)
            return 0;

        if(x < 0)
            return output * -1;
        return output;
    }
};