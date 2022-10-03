import java.util.*;
public class spiralmatrix
{
    public static void main(String args[])
    {
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter the no. of rows and columns  of array");
        int m =sc.nextInt();
        int n =sc.nextInt();
        int [][] arr =new int[m][n];
        System.out.println("Enter the elements of array");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j]=sc.nextInt();
            }
        }
        System.out.println("THE MATRIX IS");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print(arr[i][j]+"  ");
            }
            System.out.println();
        }
        System.out.println();
        int rowStart =0;
        int rowEnd =m-1;
        int colStart =0;
        int colEnd =n-1;
        
        while(rowStart <= rowEnd && colStart <= colEnd) {
            //1
            for(int col=colStart; col<=colEnd; col++) {
                System.out.print(arr[rowStart][col] + " ");
            }
            rowStart++;
   
            //2
            for(int row=rowStart; row<=rowEnd; row++) {
                System.out.print(arr[row][colEnd] +" ");
            }
            colEnd--;
   
            //3
            for(int col=colEnd; col>=colStart; col--) {
                System.out.print(arr[rowEnd][col] + " ");
            }
            rowEnd--;
   
            //4
            for(int row=rowEnd; row>=rowStart; row--) {
                System.out.print(arr[row][colStart] + " ");
          }
          colStart++;
 
          
      }
  
  


    }
}