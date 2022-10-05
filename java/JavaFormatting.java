import java.util.Scanner;

public class JavaFormatting {
    public static void main (String[] args){
        Scanner s =new Scanner(System.in);
        for (int i=0;i<3;i++){ 
        String a= s.next();
        int b = s.nextInt();
        int count=0;
        int w = b;
        while(w>0){ 
            w=b/10;
            count++;
        }
    if (count==2){ 
        System.out.println(a+"               0"+b);
    }
    else {
        System.out.println(a+"               "+b);
    }

}
s.close();
}
}