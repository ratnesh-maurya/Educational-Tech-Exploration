public class IntersectionArray{
    public static int[] intersect(int[] nums1, int[] nums2) {
     
        int temp[]=new int [nums2.length];
        int k=0;
int i=0;
while (i<nums1.length){ 
    for (int j=0;j<nums2.length;j++){
if (nums1[i]==nums2[j]){
temp[k]=nums1[i];
k++;
i++;
}
    }
    i++;
}
return temp;


// 2nd way of doing and accepted format due to time complexity

// HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
// for(int i: nums1){
// if(map.containsKey(i)){
// map.put(i, map.get(i)+1);
// }else{
// map.put(i, 1);
// }
// }
// ArrayList<Integer> list = new ArrayList<Integer>();
// for(int i: nums2){
// if(map.containsKey(i)){
// if(map.get(i)>1){
// map.put(i, map.get(i)-1);
// }else{
// map.remove(i);
// }
// list.add(i);
// }
// }
// int[] result = new int[list.size()];
// int i =0;
// while(i<list.size()){
// result[i]=list.get(i);
// i++;
// }
// return result;
}

public static void main (String[] args){
    int nums1[]={1,2,2,1};
    int nums2[]={2,2};
int ans[] = new int[nums1.length];

ans = intersect(nums1, nums2);
for (int i=0;i<ans.length;i++){
    System.out.println(ans[i]+" ");

}

} 

}

