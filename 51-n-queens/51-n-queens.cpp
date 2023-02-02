class Solution {
public:
    bool isSafeforQ(int row,int col,vector<string> &board,int n){
        int temprow = row; //Forholding the original argument values
        int tempcol = col;
        
        //For checking the upper diagonal
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            
            row--;
            col--;
        }
        
        row = temprow;
        col = tempcol;
        
        //For checking the lower diagonal direction
        while(row < n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        
        row = temprow;
        col = tempcol;
        
        //For the left direction
        while(col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        
        return true;
    }
    
    //For solving each column's case,where the queen has to be placed
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col == n){  //if all the columns has been filled with a queen
            ans.push_back(board);
            return;
        }
        
        for(int row = 0;row < n;row++){
            if(isSafeforQ(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n); //Do a dfs recursively,for this choice of row,col
                
                //backtracking step
                board[row][col] = '.';  //After returning from the col+1 call,remove Q from that pos
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int row = 0;row < n;row++){
            board[row] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};