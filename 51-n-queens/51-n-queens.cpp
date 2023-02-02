class Solution {
public:
     //For solving each column's case,where the queen has to be placed
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal,int n){
        if(col == n){  //if all the columns has been filled with a queen
            ans.push_back(board);
            return;
        }
        
        for(int row = 0;row < n;row++){
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1; //Hash value for the left direction updated to 1(occupied)
                lowerDiagonal[row+col] =1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
                
                //backtracking steps
                board[row][col] = '.';
                leftRow[row] = 0; //Hash value for the left direction updated to 0(not occupied)
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> leftRow(n, 0); //hash map for the left direction
        vector<int> lowerDiagonal(2*n-1, 0);
        vector<int> upperDiagonal(2*n-1, 0);
        string s(n, '.');
        for(int row = 0;row < n;row++){
            board[row] = s;
        }
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};