class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> spiral;
        int left = 0, right = n-1, top = 0, bottom = m-1, direction = 1;
        while(left <= right && top <= bottom){
            if(direction==1)  //row forward direction
            {
                for(int i=left;i<=right;i++) 
                    spiral.push_back(matrix[top][i]);
                direction=2;
                top++;
            }
            
            else if(direction==2) //column downward direction
            {
                for(int i=top;i<=bottom;i++) 
                    spiral.push_back(matrix[i][right]);
                direction=3;
                right--;
            }
            
            else if(direction==3) //row backward direction
            {
                for(int i=right;i>=left;i--) 
                    spiral.push_back(matrix[bottom][i]);
                direction=4;
                bottom--;
            }
            
            else if(direction==4) //column upward direction
            {
                for(int i=bottom;i>=top;i--) 
                    spiral.push_back(matrix[i][left]);
                direction=1;
                left++;
            }
        }
        return spiral;
    }
};