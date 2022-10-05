public class Search2Dmatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row=0;
    //get row number where target can lie.
    for(int i=0; i<matrix.length; i++){
    if(target == matrix[i][0])
    return true;
    
            if (target < matrix[i][0]){
                 row =(i==0)? 0 : i-1;
                 break;
            }else
                 row=matrix.length-1;
          
        }
        
       //search for target in particular one row. 
         for(int i=0; i<matrix[0].length; i++){
          if(target == matrix[row][i])
                return true;
         
         }
        return false;
        
        }
}
