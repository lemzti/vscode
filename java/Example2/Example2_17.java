import java.util.Scanner;

public class Example2_17 {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.println("Enter first name, last name, age, and weight (separated by spaces): ");

        String firstName = input.next();
        String lastName = input.next();

        int age = input.nextInt();
        float weight = input.nextFloat();

        System.out.printf("Name: %s %s\n", firstName, lastName);
        System.out.printf("Age: %d\nWeight: %.1f", age, weight);

        input.close();
    }
}