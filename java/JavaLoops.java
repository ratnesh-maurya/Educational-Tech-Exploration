import java.util.Scanner;

public class JavaLoops {
    public static void main( String[] args){
        Scanner s =new Scanner(System.in);
        int n = s.nextInt();
        if (n>=2 && n<=20){
        for ( int i=1;i<=10;i++){
            int result=n*i;
            System.out.println(n+" x "+i+" = "+result);
        }
    }
s.close();
}
}
