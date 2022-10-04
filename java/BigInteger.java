import java.util.Scanner;

public class BigInteger{ 
public static void main(String[] args) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    Scanner scan = new Scanner(System.in);
    java.math.BigInteger A = scan.nextBigInteger();
    java.math.BigInteger B = scan.nextBigInteger();
    
    System.out.println(A.add(B));
    System.out.println(A.multiply(B));

    scan.close();
}
}