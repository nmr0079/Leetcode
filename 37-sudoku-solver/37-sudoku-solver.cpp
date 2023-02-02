class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);  //a recursive boolean fn,which returns true after filling the whole board
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){  //both i and j will go from 0 -> 8
                if(board[i][j] == '.'){ //If there is an empty cell
                    for(char c = '1';c <= '9';c++){ //trying out all possible entries
                            if(isValid(board,i,j,c)){ //given the row,col, returns true if c doesn't violate
                                  board[i][j] = c;                     //any of the 3 given rules
                                  if(solve(board) == true)  //checks if the entry c leads to valid solution
                                      return true;
                                  else
                                      board[i][j] = '.'; //bactrack and remove the entry c,if it leads to an
                            }                             //invalid solution
                    }
                    return false;  //If none of the c's can be filled in the empty space,then backtrack
                }
            }
        }
        return true;
    }
    
    //This function checks whether the entry c violates any of the 3 given rules or not
    bool isValid(vector<vector<char>>& board,int row, int col,char c){
        for(int i = 0;i < 9;i++){
            if(board[i][col] == c)  //if in the same column,c already exists
                return false;
             if(board[row][i] == c)  //if in the same row,c already exists
                return false;
             if(board[3 * (row/3) + i / 3][3 * (col/3) + i % 3] == c)  //if in the same 3x3 sub matrix,it exi
                return false;
        }
        return true;  //If it doesn't violate any of the rules
    }
};