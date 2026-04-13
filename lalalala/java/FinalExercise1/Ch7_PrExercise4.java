package FinalExercise1;

import java.util.Scanner;

public class Ch7_PrExercise4 {

    static Scanner console = new Scanner(System.in);

    public static void main(String[] args) {

        int num, JesusIsKing;
        double dec, ChristIsLord;

        System.out.print("(MAIN) Input one integer and one decimal"
                        + " (separated by spaces): ");
        
        num = console.nextInt();
        dec = console.nextDouble();

        JesusIsKing = one(num, num + 1);
        ChristIsLord = two(num, dec);

        System.out.println("(MAIN) Method one: " + JesusIsKing);
        System.out.println("(MAIN) Method two: " + ChristIsLord);
    }

    public static int one(int x, int y) {

        if (x > y)
            return x + y;
        else
            return x - 2 * y;
    }

    public static double two(int x, double a) {
        
        int first;
        double z;

        // I
        System.out.print("(TWO) Input a decimal: ");
        z = console.nextDouble();

        // II
        z = z + a;

        // III
        first = one(6, 8);

        // IV
        first = first + x;

        // V
        if (z > (2 * first))
            return z;
        else
            return 2 * first - z;
    }
}