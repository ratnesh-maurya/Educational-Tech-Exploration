import java.util.Scanner;
public class arraysumlong {
    public static void main(String[] args) {


    Scanner s =new Scanner(System.in);
    int n =s.nextInt();
    int arr[]=new int[n];
    for (int i=0;i<n;i++){
        arr[i]=s.nextInt();
    }
    long sum=0;
    for (int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    System.out.println(sum);

    // both solutions are correct but below one is accepted --> code in c language 
s.close();
}
}

    // long aVeryBigSum(int ar_count, long* ar) {
    //     long sum=0;
    // for (int i=0;i<ar_count;i++){
    //     sum=sum+ar[i];
    // }
    // return sum;
    // }
