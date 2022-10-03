import java.util.Arrays;

// this is Bubble sort algorithm code
public class Bubble_sort {
    public static void main(String[] args) {
        int[] arr = {-43,45,-87,-24,10};
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void bubbleSort(int[] nums){
        boolean swapped = false;
        // runs n-1 times
        for (int i = 0; i < nums.length; i++) {
            // for each step, max item will come at the last respective index
            for (int j = 1; j < nums.length - i; j++) {
                // swap the item if it is smaller than previous item
                if(nums[j] < nums[j-1]){
                    //swap
                    int temp = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = temp;
                    swapped = true;
                }
            }
            // if the array is sorted and swap doesn't take place then you have
            // to stop the checking
            if(!swapped)
                break;
        }
    }
}
