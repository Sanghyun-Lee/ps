class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        stack<pair<int, int>> st;       
        vector<vector<int>> ret(image.size(), vector<int>(image[0].size(), 0));
        int val = image[sr][sc];
        st.push(pair<int, int>(sr, sc));
        std::copy(image.begin(), image.end(), ret.begin());
        

        while(st.size() > 0) {
            int y = st.top().first;
            int x = st.top().second;
            st.pop();

            if(image[y][x] == val) {
                ret[y][x] = newColor;
                image[y][x] = -1;
            }
            
            if(0 <= y - 1 && image[y - 1][x] == val)
                st.push(pair<int, int>(y - 1, x));
            
            if(0 <= x - 1 && image[y][x - 1] == val)
                st.push(pair<int, int>(y, x - 1));
            
            if(y + 1 < image.size() && image[y + 1][x] == val)
                st.push(pair<int, int>(y + 1, x));
            
            if(x + 1 < image[0].size() && image[y][x + 1] == val)
                st.push(pair<int, int>(y, x + 1));
        }
        
        return ret;
    }
};