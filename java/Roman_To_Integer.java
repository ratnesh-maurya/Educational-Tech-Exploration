import java.util.*;

class LeetCode{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println(romanToInt(str));
    }

    static int romanToInt(String s) {
        char prev = s.charAt(0);
        int val = assignVal(prev);
        for(int i=1;i<s.length();i++){
            char ch = s.charAt(i);
            int newval=0;
            if( (ch == 'V' || ch == 'X') && prev == 'I'){
                newval = assignVal(ch) - assignVal(prev);
                val -= assignVal(prev);
            }
            else if( (ch == 'L' || ch == 'C') && prev == 'X'){
                newval = assignVal(ch) - assignVal(prev);
                val -= assignVal(prev);
            }
            else if( (ch == 'M' || ch == 'D') && prev == 'C'){
                newval = assignVal(ch) - assignVal(prev);
                val -= assignVal(prev);
            }
            else{
                System.out.println("ch: " + ch);
                newval = assignVal(ch);
            }
            prev = ch;
            val += newval;
        }
        return val;
    }
    
    static int assignVal(char ch){
        if(ch == 'I') return 1;
        else if(ch == 'I') return 1;
        else if(ch == 'V') return 5;
        else if(ch == 'X') return 10;
        else if(ch == 'L') return 50;
        else if(ch == 'C') return 100;
        else if(ch == 'D') return 500;
        else if(ch == 'M') return 1000;
        return 0;
    }
}