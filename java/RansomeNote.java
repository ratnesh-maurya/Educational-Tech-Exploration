import java.util.*;
public class RansomeNote {
    public boolean canConstruct(String ransomNote, String magazine) {

    int[] arr = new int[26];
    Arrays.fill(arr, 0);
    for (char c : magazine.toCharArray()) {
        arr[c - 'a']++;
    }
    for (char c : ransomNote.toCharArray()) {
        arr[c - 'a']--;
        if (arr[c - 'a'] < 0) {
            return false;
        }
    }
    return true;

}
}