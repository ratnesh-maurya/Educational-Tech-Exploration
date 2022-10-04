package DP;
import java.util.*;
public class LongestCommonSubstring {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String x = in.nextLine();
        String y = in.nextLine();
        System.out.println(LCS(x,y,x.length(),y.length()));
        in.close();
    }
    private static int LCS(String x, String y, int n, int m) {
        int t[][] = new int[n+1][m+1];
        for (int i = 1; i < n+1; i++) 
        {
            for (int j = 1; j < m+1; j++) 
            {
                if (x.charAt(i-1) == y.charAt(j-1)) 
                {
                    t[i][j] = 1 + t[i-1][j-1];
                } 
                else 
                {
                    t[i][j] = 0;
                }
            }    
        }
        int max = 0;
        for (int i = 0; i < n+1; i++) 
        {
            for (int j = 0; j < m+1; j++) 
            {
                max = Math.max(t[i][j], max);
            }
        }
        return max;
    }
}
