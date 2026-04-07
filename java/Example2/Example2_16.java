import java.util.Scanner;

public class Example2_16 {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter two integers separated by spaces: ");

        int ft = input.nextInt();
        int in = input.nextInt();

        System.out.printf("Feet = %d\nInches = %d", ft, in);

        input.close();
    }
}