class Solution {
public:
    int stairs[46] = {0};

    int climbStairs(int n) {
        if(n == 0)
            return 1;
        else if(n < 0)
            return 0;

        if(stairs[n] > 0)
            return stairs[n];

        stairs[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return stairs[n];
    }
};