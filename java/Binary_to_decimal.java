public class Binary_to_decimal {
    public static void main(String[] args) {
        long n = 101;
        System.out.println(convert(n));
    }
    public static int convert(long n){
        int decimal = 0, i =0;

        while (n != 0) {
            long rem = n % 10;
            decimal += rem * Math.pow(2, i);
            n = n / 10;
            i++;
        }
        return decimal;

    }
}
