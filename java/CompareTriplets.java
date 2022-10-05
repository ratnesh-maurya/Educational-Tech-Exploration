import java.util.Scanner;

    // both solutions are correct but below one is accepted --> code in c language 


public class CompareTriplets {
    public static void main(String[] args){
        Scanner s =new Scanner(System.in);

        int a []= new int[3];
        int b []=new int[3];
        int alice =0;
        int bob=0;

        for (int i=0;i<3;i++){
            a[i]=s.nextInt();
        }
        for (int i=0;i<3;i++){
            b[i]=s.nextInt();
        }
        for (int i=0;i<3;i++){

if (a[i]==b[i]){
continue;
}
else if (a[i]>b[i]){
alice++;
}
else{
    bob++;
}
}

int ans[]=new int[2];

ans[0]=alice;
ans[1]=bob;
for (int i=0;i<ans.length;i++){ 

    System.out.print(ans[i]);

}
s.close();
}
}

// public static List<Integer> compareTriplets(List<Integer> a, List<Integer> b) {



    // 2nd method in c language 
    
//     int  Alice_point = 0,  Bob_point = 0;
//    for(int i = 0; i<a_count; i++)
//    {
//        if(a[i]==b[i])
//        {
          
//        }

//        if(a[i]>b[i])
//        {
//            Alice_point += 1;
          
//        }
//         if(a[i]<b[i])
//        {
//            Bob_point += 1;
           
//        }

//    }
    
//     *result_count = 2;
   
//     static int c[2];
//      c[0]  = Alice_point;
//      c[1] = Bob_point;
//     return c;
