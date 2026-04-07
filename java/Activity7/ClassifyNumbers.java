import java.util.Scanner;

public class ClassifyNumbers {
    
    static Scanner console = new Scanner(System.in);

    static final int N = 10;

    public static void main(String[] args) {
        
        int counter, number;
        int zeroes = 0, odds = 0, evens = 0;

        System.out.println("Please enter " + N + " integers "
                        +  "(positive, negative, or zeroes):");

        for (counter = 1; counter <= N; counter++) {
            number = console.nextInt();
            System.out.print(number + " ");

            switch (number % 2) {
                case 0:
                    evens++;
                    if (number == 0) {
                        zeroes++;
                    }
                    break;
                case 1:
                case -1:
                    odds++;
            } // end switch
        } // end for

        System.out.println();

        System.out.println("There are " + evens + " evens, "
                        + "which also includes "
                        + zeroes + " zeroes.");
        System.out.println("Total number of odds is: " + odds);
    }
}
