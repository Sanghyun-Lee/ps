class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int area = INT_MIN;
        
        while(start < end) {
            int h = min(height[start], height[end]);
            
            area = max(area, (end - start) * h);
            
            
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        
        return area;
    }
};