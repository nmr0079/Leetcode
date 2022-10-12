class Solution {
    public double largestTriangleArea(int[][] points) {
        double max = 0.0;
        int n = points.length;
        for(int i = 0;i < n-2;i++){
            for(int j = i+1;j < n-1;j++){
                for(int k = j+1;k < n;k++)
                    max = Math.max(max, area(points[i],points[j],points[k]));
            }
        }
        return max;
    }
    
    public double area(int[] x,int[] y,int[] z){
        return Math.abs(x[0]*(y[1]-z[1])+y[0]*(z[1] - x[1])+ z[0]*(x[1] - y[1]))/2.0;
    }
}