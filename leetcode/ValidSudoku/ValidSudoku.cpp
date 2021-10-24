class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cc[10] = {0};
        int rc[10] = {0};
        int sc[10] = {0};
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] != '.') {
                    int idx = (int)(board[i][j] - '0');
                    rc[idx]++;
                    if(rc[idx] > 1)
                        return false;
                }

                if(board[j][i] != '.') {
                    int idx = (int)(board[j][i] - '0');
                    cc[idx]++;
                    if(cc[idx] > 1)
                        return false;
                }
                
                int r = (3 * (i / 3)) + (j / 3);
                int c = (3 * (i % 3)) + (j % 3);
                if(board[r][c] != '.') {
                    int idx = (int)(board[r][c] - '0');
                    sc[idx]++;
                    if(sc[idx] > 1) {
                        return false;
                    }
                }
            }
            memset(cc, 0, sizeof(int) * 10);
            memset(rc, 0, sizeof(int) * 10);
            memset(sc, 0, sizeof(int) * 10);
        }
        return true;
    }
};