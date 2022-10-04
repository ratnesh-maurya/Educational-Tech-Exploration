public class MaximumSubarray {
    public int maxSubArray(int[] nums) {
        int size = nums.length;
        int max = Integer.MIN_VALUE, maxBefore= 0;
  
        for (int i = 0; i < size; i++)
        {
            maxBefore = maxBefore+ nums[i];
            if (max < maxBefore)
                max = maxBefore;
            if (maxBefore < 0)
                maxBefore = 0;
        }
        return max;
   
    }
}
