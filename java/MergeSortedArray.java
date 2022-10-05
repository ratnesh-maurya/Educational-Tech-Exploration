public class MergeSortedArray {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
    

int ans[]=new int[nums1.length];
int k=0;
int i=0;
int j=0;
        while (i<m && j<n){
            
               if (nums1[i]<=nums2[j]){
                ans[k]=nums1[i];
                k++;
                i++;
               }
               else {
                 ans[k]=nums2[j];
                 j++;
                 k++;
               }
            }
        
while (i<m){
ans[k]=nums1[i];
i++;
k++;
}
while (j<n){
    ans[k]=nums2[j];
    j++;
    k++;
}


for (int a=0;a<nums1.length;a++){
    nums1[a]=ans[a];
}


//  2nd way of doing this question 


// int i = m - 1;     
// int j = n - 1;     
// int k = m + n - 1; 

// while (j >= 0)
//   if (i >= 0 && nums1[i] > nums2[j])
//     nums1[k--] = nums1[i--];
//   else
//     nums1[k--] = nums2[j--];







    }

}
