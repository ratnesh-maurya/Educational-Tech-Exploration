import java.util.Scanner;

public class Stdin_StdoutII {
    public static void main ( String[] args ){
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        double b = s.nextDouble();
        s.nextLine();
        // line no. 8 is important string ka next line function immediately after integer ya double nahi aa sakta 
        String c = s.nextLine();

        System.out.println("String:"+c);
        System.out.println("Double:"+b);
        System.out.println("Int:"+a);

    s.close();
}
}
