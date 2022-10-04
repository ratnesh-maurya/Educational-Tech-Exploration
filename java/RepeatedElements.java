import java.util.HashSet;
import java.util.Set;
public class RepeatedElements {
    public static void main(String[] args) {
        int a[]={5,3,4,3,2,2,1};
        Set<Integer> s=new HashSet<>();
        System.out.print("Repeated element's are: ");
        for(int i:a){
            if(s.add(i)==false){
                System.out.print(i+" ");
            }
        }
    }
}
