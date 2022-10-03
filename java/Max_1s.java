 //we had given a array in which we have to the max. no of 1 present

 public class Max_1s {
    public static void main(String[] args) {
        int[] nums = {1,0,1,1,0,1};
        int count = 0;
        int max;
        max = Integer.MIN_VALUE;
        for (int num : nums) {
            if (num == 1) count++;
            else count = 0;
            if(max < count)
                max = count;
        }
        System.out.println(max);
    }
}
