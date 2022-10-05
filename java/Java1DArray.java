import java.util.Scanner;

public class Java1DArray {
    public static void main(String[] args)  {
Scanner s = new Scanner(System.in);
int n =s.nextInt();

int result[]=new int [n];
for (int i=0;i<n;i++){
    result[i]=s.nextInt();
}
for (int i=0;i<n;i++){
    System.out.println(result[i]);
}
s.close();
}
}