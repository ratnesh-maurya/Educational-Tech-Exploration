import java.util.Scanner;

// code not understood hasNext function use kiya hai 
public class JavaEndofLine {
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int lines = 1;
		while (true)
		{
			String line = input.nextLine();
			System.out.println(lines + " " + line);
			lines++;
			if (!input.hasNext())
			{
				break;
			}
		}
		input.close();

        
    }
}
