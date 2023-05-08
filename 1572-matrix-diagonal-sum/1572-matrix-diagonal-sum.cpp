class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        for(int i = 0;i < n;i++){  //sum of primary diagonals
            sum += mat[i][i];
        }
        int c = n-1;
        for(int j = 0;j < n;j++){
            if(j != c)
                sum += mat[c][j];
            c--;
        }
        
        return sum;
    }
};