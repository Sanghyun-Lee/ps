class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ret;
        int l = area;
        int w = 1;

        for(int i = area - 1; i > 1; i--) {
            if(area % i != 0)
                continue;
            
            int newL = i;
            int newW = area / i;
            
            if(newL < newW)
                break;

            if((l - w) > (newL - newW)) {
                w = newW;
                l = newL;
            }
        }

        ret.push_back(l);
        ret.push_back(w);        
        
        return ret;
    }
};