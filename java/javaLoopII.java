import java.util.Scanner;



public class javaLoopII {
    public static void main ( String[] args ){
        Scanner s = new Scanner(System.in);
        int q = s.nextInt();
        for (int i=0;i<q;i++){
            int a = s.nextInt();
            int b = s.nextInt();
            int n = s.nextInt();
            int d = a+(2^0*b);
            System.out.print(d+" ");

            for (int j=1;j<n;j++){
                d=d+j*2*b;
                System.out.print(d+" ");
            }

        }
        System.out.println();
    s.close();
}
}
