public class TwoSum {
    public static int[] twoSum(int[] nums, int target) {

        int ans []=new int [2];
if (nums.length==0 || nums.length==1){
    return nums;
}
for (int i=0;i<nums.length;i++){ 
    for (int j=i+1;j<nums.length;j++){ 
        
if (nums[i]+nums[j]==target){
ans[0]=i;
ans[1]=j;

}
}
}
return ans;
}
public static void main (String [] args){
     
    int ans [] ={2,5,5,11};
    int a[]=new int [2];
    a=twoSum(ans, 10);
    for (int i=0;i<a.length;i++){ 
       System.out.println(a[i]+" ");

   }
}
}
//  time complexity is n^2