public class PalindromeFOR {
    public static void main(String[] args) {
      String value = "radar"; // Replace word
      String temp = "";
      for (int i = value.length() - 1; i >= 0; i--) {
        temp = temp + (value.charAt(i));
      }
      System.out.println(temp);
    }
}
