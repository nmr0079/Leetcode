class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int left = 0, right = n-1, top = 0, bottom = n-1, direction = 1, elem = 1;
        while(left <= right && top <= bottom){
            if(direction == 1) //For the first row in the spiral
            {
                for(int i = left;i <= right;i++)
                    matrix[top][i] = elem++;
                top++;
                direction = 2;
            }
            else if(direction == 2) //For the last col in the spiral
            {
                for(int i = top;i <= bottom;i++)
                    matrix[i][right] = elem++;
                right--;
                direction = 3;
            }
            else if(direction == 3) //For the last row in the spiral
            {
                for(int i = right;i >= left;i--)
                    matrix[bottom][i] = elem++;
                bottom--;
                direction = 4;
            }
            else if(direction == 4)  //For the first col in the spiral
            {
                for(int i = bottom;i >= top;i--)
                    matrix[i][left] = elem++;
                left++;
                direction = 1;
            }
            else
                continue;
        }
        return matrix;
    }
};