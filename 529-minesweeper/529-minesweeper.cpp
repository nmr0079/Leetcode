class Solution {
    private:
        int n = -1, m = -1;
    
        void reveal(int i, int j, vector<vector<char>>& board) {
            static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
            static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
            if (i < 0 || i >= n || j < 0 || j >= m) 
                return;
            else if (board[i][j] == 'M') 
                board[i][j] = 'X';
            else if (board[i][j] == 'E') 
            {
                char surrounding = '0';
                for (int k = 0; k < 8; k++)
                    if (i + rowNbr[k] < 0 || i + rowNbr[k] >= n) 
                        continue;
                    else if (j + colNbr[k] < 0 || j + colNbr[k] >= m) 
                        continue;
                    else if (board[i + rowNbr[k]][j + colNbr[k]] == 'M' || board[i + rowNbr[k]][j + colNbr[k]] == 'X')
                        surrounding++;
        
                if (surrounding != '0') board[i][j] = surrounding;
                else {
                    board[i][j] = 'B';
                    for (int k = 0; k < 8; k++) 
                        reveal(i + rowNbr[k], j + colNbr[k], board);
                    }
                }
        }
    
    public:
        vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& p) {
            n = size(board), m = size(board[0]);
            reveal(p[0], p[1], board);
            return board;
    }
};