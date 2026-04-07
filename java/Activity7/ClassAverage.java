import java.io.*;
import java.util.*;

public class ClassAverage {
    
    public static void main(String[] args) throws FileNotFoundException {
        
        String firstName, lastName;
        double testScore;
        char grade = ' ';
        double classAverage;

        double sum = 0;
        int count = 0;

        Scanner inFile = new Scanner(new FileReader("stData.txt"));
        PrintWriter outFile = new PrintWriter("stData.out");

        while (inFile.hasNext()) {
            firstName = inFile.next();
            lastName = inFile.next();
            testScore = inFile.nextDouble();

            sum = sum + testScore;
            count++;

            // Determine grade
            switch ((int) testScore / 10) { // 4
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    grade = 'F';
                    break;
                case 6:
                    grade = 'D';
                    break;
                case 7:
                    grade = 'C';
                    break;
                case 8:
                    grade = 'B';
                    break;
                case 9:
                case 10:
                    grade = 'A';
                    break;
                default:
                    System.out.println("Invalid score.");
            } // end switch

            outFile.printf("%-12s %-12s %4.2f %c %n",
                            firstName, lastName,
                            testScore, grade);
        } // end while

        outFile.println();

        if (count != 0) {
            outFile.printf("Class Average: %.2f %n",
                            sum / count);
        } else {
            outFile.println("No data.");
        }

        outFile.close();
    }
}
