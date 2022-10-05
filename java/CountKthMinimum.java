import java.util.*;
 
class CountKthMinimum
{
 
    // Function to find the K-th minimum element
    // from an array concatenated M times
    static int KthMinValAfterMconcatenate(int[] A, int N, int M, int K)
    {
        // Sort the elements in
        // ascending order
        Arrays.sort(A);
 
        // Return the K'th Min element
        // present at ( (K-1) / M ) index
        return (A[((K - 1) / M)]);
    }
 
    // Driver Code
    public static void main(String[] args)
    {
 
        int[] A = {3, 1, 2};
 
        int M = 3, K = 4;
        int N = A.length;
 
        System.out.println(KthMinValAfterMconcatenate(A, N, M, K));
    }
}

// Time Complexity: O(N * log N)
// Auxiliary Space: O(1) 
