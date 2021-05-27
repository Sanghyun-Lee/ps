class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> isVisited(n, 0);
        vector<int> ans;
        
        for(int i = 0; i < edges.size(); i++) {
            isVisited[edges[i][1]]++;
        }

        for(int i = 0; i < isVisited.size(); i++) {
            if(isVisited[i] == 0)
                ans.push_back(i);
                
        }
        return ans;
    }

};
