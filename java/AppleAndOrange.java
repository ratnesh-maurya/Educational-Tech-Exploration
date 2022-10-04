import java.util.List;

public class AppleAndOrange{
    public static void countApplesAndOranges(int s, int t, int a, int b, List<Integer> apples, List<Integer> oranges) {
int temp []=new int [apples.size()];
int temp2[]=new int [oranges.size()];
        for (int i=0;i<apples.size();i++){
             temp[i]=apples.get(i)+a;
        }
        for (int i=0;i<oranges.size();i++){
            temp2[i]=oranges.get(i)+b;
       }
int applesCount=0;       
for (int i=0;i<temp.length;i++){
if (temp[i]>=s && temp[i]<=t){
    applesCount++;
}
}
int orangesCount=0;       
for (int i=0;i<temp2.length;i++){
if (temp2[i]>=s && temp2[i]<=t){
    orangesCount++;
}
}

System.out.println(applesCount);
System.out.println(orangesCount);
}
}