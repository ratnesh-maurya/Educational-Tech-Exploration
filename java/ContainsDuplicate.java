public class ContainsDuplicate {
    public boolean containsDuplicate(int[] nums) {

for (int i=0;i<nums.length;i++){
    for (int j=i+1;j<nums.length;j++){
        if (nums[i]==nums[j]){
            return true ;
        }
    }
}
return false;

//  time complexity is n^2



//  2nd way of solving by hashsets

// Set<Integer> set=new HashSet<>();
    
// for(int num: nums)
// {
    
//     if(set.contains(num))
//         return true;
    
//     set.add(num);
    
// }

// return false;

}
}