//Spiral Matrix - Leetcode
//Leetcode link: https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> v;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int total = row*col;
        int count = 0;
        
        int firstRow =0;
        int firstCol =0;
        int lastRow =row-1;
        int lastCol =col-1;
        
        while(count < total){
            
            for(int i = firstCol; count < total && i <= lastCol; i++){
                v.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++;
            for(int i = firstRow; count < total && i <= lastRow; i++){
                v.push_back(matrix[i][lastCol]);
                count++;
            }
            lastCol--;
            for(int i = lastCol; count < total && i >= firstCol; i--){
                v.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--;
            for(int i = lastRow; count < total && i >= firstRow; i--){
                v.push_back(matrix[i][firstCol]);
                count++;
            }
            firstCol++;
            
        }
        return v;
    }
};