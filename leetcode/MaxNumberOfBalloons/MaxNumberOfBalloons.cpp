class Solution {
    int cache[26] = {0, };
public:
    int maxNumberOfBalloons(string text) {
        string strAns = "balloon";

        for(int i = 0; i < text.size(); i++)
            cache[text[i] - 'a']++;

        cache['l' - 'a'] = cache['l' - 'a'] / 2;
        cache['o' - 'a'] = cache['o' - 'a'] / 2;

        int count = INT_MAX;
        for(int i = 0; i < strAns.size(); i++) {
            if(cache[strAns[i] - 'a'] < count)
                count = cache[strAns[i] - 'a'];
        }
        
        return count;
    }
};