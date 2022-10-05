import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MissingNumber {
    public static List<Integer> missingNumbers(List<Integer> arr, List<Integer> brr) {
        List<Integer> result= new ArrayList<>();
        Map<Integer,Integer> fbrr=new HashMap<>();
        for(Integer val:brr){
            fbrr.put(val,fbrr.getOrDefault(val, 0)+1);
        }
        for(Integer val:arr){
            if(fbrr.containsKey(val)){
                fbrr.put(val,fbrr.getOrDefault(val, 0)-1);
            }
        }
        
        for(Map.Entry<Integer,Integer> entry:fbrr.entrySet()){
            if(entry.getValue()>0){
                result.add(entry.getKey());
            }
        }
        return result;
}
}