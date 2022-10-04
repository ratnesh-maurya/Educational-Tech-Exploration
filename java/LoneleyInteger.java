import java.util.List;

public class LoneleyInteger {
    public static int lonelyinteger(List<Integer> a) {
        int ans =a.get(0);
for (int i=1;i<a.size();i++){
     ans = ans ^a.get(i);
}
return ans;
}
}