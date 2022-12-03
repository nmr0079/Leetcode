class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), cols(9), blocks(9);
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.')
                    continue;
                int cur_val = board[i][j];
                if(rows[i].count(cur_val) || cols[j].count(cur_val) || blocks[(i/3)*3 + j/3].count(cur_val))
                    return false;  //count function returns 1 if value is already present in row or column or block otherwise it will return 0
                
                rows[i].insert(cur_val);
                cols[j].insert(cur_val);
                blocks[(i/3)*3 + j/3].insert(cur_val);
            }
        }
        
        return true;
    }
};