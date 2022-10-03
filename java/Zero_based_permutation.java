/*  (zero based permutation): let me give a example for better understanding
 *     here in array below the values of indeces shows which index they have to be placed
 *  inside the array like 5 is need to be on 5th index so in output 5 will be at 5th index
 * 
*/

import java.util.Arrays;

public class Zero_based_permutation {
    public static void main(String[] args) {
        int[] nums = {0,2,1,5,3,4};
        System.out.println(Arrays.toString(buildArray(nums)));
    }
    static int[] buildArray(int[] nums) {
        int[] ans = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int a = nums[nums[i]];
            ans[i] = a;
        }
        return ans;
    }
}
