import java.util.Scanner;

// below solution is correct not this code in c language 

public class Datatypes {
    public static void main (String[] args){
        Scanner s =new Scanner(System.in);
        int t =s.nextInt();
        for (int i=0;i<t;i++){
            int n =s.nextInt();
            int a = Integer.bitCount(n);
            if (a<=16){
                System.out.println(n+" can be fitted in:");
                System.out.println("* short");
                System.out.println("* int");
                System.out.println("* long");
            }
            else if(a<=32 ) {
                System.out.println(n+" can be fitted in:");

                System.out.println("* int");
                System.out.println("* long");

            }
            
            

            else if (a<=64 ){
                System.out.println(n+" can be fitted in:");
                System.out.println("* long");

            }
            else  {
                System.out.println(n+" can't be fitted anywhere.");

            }
        }
        s.close();
    }
}



// 2nd method of doing which is accepted

// Scanner sc = new Scanner(System.in);
// int t=sc.nextInt();

// for(int i=0;i<t;i++)
// {

//     try
//     {
//         long x = sc.nextLong();
        
//         // Java Datatypes - HackerRank Solution START
        
//         System.out.println(x+" can be fitted in:");
//         if(x>=-128 && x<=127)
//         {
//             System.out.println("* byte");
//         }
//         if(x>=-32768 && x<=32767)
//         {
//             System.out.println("* short");
//         }
//         if(x>=-2147483648 && x<=2147483647)
//         {
//             System.out.println("* int");
//         }
//         System.out.println("* long");
        
//         // Java Datatypes - HackerRank Solution END
//     }
//     catch(Exception e)
//     {
//         System.out.println(sc.next()+" can't be fitted anywhere.");
//     }

// }
