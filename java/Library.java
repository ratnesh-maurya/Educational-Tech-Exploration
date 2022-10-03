
import java.util.Scanner;

class meth {

    String name[] = new String[9999999];
    int qty[] = new int [99999999],c=0;
    int count[] = new int [99999999];

    public void showAvailableBooks() {
        System.out.println((c==0)?"No Book is available":(c>0)?"Available Books are:":"There is only one book available");
        for (int i = 0; i < c; i++) {
            System.out.println((qty[i]>0)?((i+1)+") "+name[i]):((i+1)+") "+name[i]+" (currently unavailable)"));
        }
        System.out.println();
    }

    public void addBook(String add, int q) {
        add = add.replace('_', ' ');
        int j=0;
        for (int i = 0; i < c; i++) {
            if(name[i].compareToIgnoreCase(add)==0) {
                qty[i] += q;
                j++;
                break;
            }
        }

        if(j==0) {
            name[c] = add;
            count[c] += q;
            qty[c] += q;
            c++;
            System.out.println((q==1)?"the book "+add+" has been successfully added in the library.":(q>1)?q+" copies of "+add+" has been successfully added in the library.":"Practically it's not possible to add 0 book.");
        }
        System.out.println();
    }

    public void issueBooks(String issue) {
        if(c>0) {
            issue = issue.replace('_', ' ');
            for (int i = 0; i < c; i++) {
                if(issue.compareToIgnoreCase(name[i])==0)
                {
                    if(qty[i]>0) {
                        System.out.println("Book "+issue+" has been issued successfully.");
                        qty[i]--;
                        break;
                    }
                    else {
                        System.out.println("Book "+issue+" is curently unavailable in the library.");
                    }
                }
            }
        }
        else {
            System.out.println("No book is curently unavailable in the library.");
        }
        System.out.println();
    }

    public void returnBooks(String ret) {
        int f=0;
        ret = ret.replace('_', ' ');
        for (int i = 0; i < c; i++) {
            if(ret.compareToIgnoreCase(name[i])==0 && count[i]>=qty[i] )
            {
                System.out.println("Book "+ret+" has been returned successfully.");
                qty[i]++;
                f++;
                break;
            }
        }
        if(f==0) {
            System.out.println("Book "+ret+" was not issued from this library.");
        }
        System.out.println();
    }

    public void showCommands() {
        System.out.println("\nYou can use the following commands:\nType 1 to view the available books.\nType 2 to add a book.\nType 3 to issue a book.\nType 4 to return a book.\nType 5 to view commands again.\nType 6 to exit library.\n ");
    }

}


// Please edit the class name if it is throwing error.
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        meth lib = new meth(); 
        int k=0;
        System.out.println("\nWelcome to the library!\n");
        lib.showCommands();

        do {

            switch(in.nextInt()) {
                case 1: lib.showAvailableBooks();
                break;

                case 2: System.out.println("Enter the name(use \"_\" instead of space) and quantity of the book that you want to add:");
                lib.addBook(in.next(), in.nextInt());
                break;

                case 3: System.out.println("Enter the name(use \"_\" instead of space) of the book that you want to issue:");
                lib.issueBooks(in.next());
                break;

                case 4: System.out.println("Enter the name(use \"_\" instead of space) of the book that you want to return:");
                lib.returnBooks(in.next());
                break; 

                case 5: lib.showCommands();
                break;

                case 6: System.out.println("Thanks for visiting!");
                k=5;


            }
        } 

        while(k!=5);

        in.close();

    }
}
