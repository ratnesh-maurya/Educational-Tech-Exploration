public class ValidAnagram {
    public boolean isAnagram(String s, String t) {

            // if lengths are unequal return false
            if(s.length() != t.length()) {
                return false;
            }
            // else hold 2 arrays which tells us the alphabets count
            int[] s_arr = new int[26];
            int[] t_arr = new int[26];
            // iterate and increment respective indices
            for(int i=0;i<s.length();i++) {
                s_arr[(int)s.charAt(i)-97]++;
                t_arr[(int)t.charAt(i)-97]++;
            }
            // check if they are same
            for(int i=0;i<26;i++) {
                if(s_arr[i] != t_arr[i])
                    return false;
            }
            return true;
}
}