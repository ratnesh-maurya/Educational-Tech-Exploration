
// here we had an array we have to find sqaures if them
 
public class Square_of_Sorted_array {
    public static void main(String[] args) {
        int [] nums = {-4,-1,0,3,10};
        for(int i = 0 ; i < nums.length ; i++){
            nums[i] = nums[i]*nums[i];
        }
        int temp;
        for(int i = 0 ; i < nums.length ; i++){
            for(int j = i+1 ; j < nums.length ; j++){
                if(nums[i] > nums[j]){
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        for(int x : nums) System.out.println(x);
    }
}
