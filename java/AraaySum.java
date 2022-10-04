import java.util.Scanner;

public class AraaySum {
    public static void main(String[] args) {

    // both solutions are correct but below one is accepted --> code in c language 

        Scanner s =new Scanner(System.in);
        int n =s.nextInt();
        int arr[]=new int[n];
        for (int i=0;i<n;i++){
            arr[i]=s.nextInt();
        }
        int sum=0;
        for (int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        System.out.println(sum);
     s.close();   
    }
}



// int simpleArraySum(int ar_count, int* ar) {
//     int i;
//     int sum = 0;
//     for(i=0;i < ar_count;i++)
//     {   
//          sum = sum + ar[i];
//     }
//     return sum;
