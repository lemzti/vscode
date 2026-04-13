import java.io.*;
import java.util.*;


public class DataComparison
{
    public static void main(String[] args)
                            throws FileNotFoundException
    {
        String courseId1, courseId2;    // course ID for both groups            // Step 1
        int numberOfCourses;
        double avg1, avg2;              // average of a course in each group
        double avgGroup1, avgGroup2;    // average of each group

        Scanner group1 =                                                        // Step 2
                    new Scanner(new FileReader("group1.txt"));
        Scanner group2 =
                    new Scanner(new FileReader("group2.txt"));
        PrintWriter outFile = new PrintWriter("student.out");

        avgGroup1 = 0.0;                                                        // Step 3
        avgGroup2 = 0.0;                                                        // Step 4
        numberOfCourses = 0;                                                    // Step 5

        outFile.println("Course ID    Group No    Course Average");             // Step 6 - print heading
        
        while (group1.hasNext() && group2.hasNext())                            // Step 7
        {
            courseId1 = group1.next();                                          // Step 7a
            courseId2 = group2.next();                                          // Step 7b

            if (!courseId1.equals(courseId2))                                   // Step 7c
            {
                System.out.println("Data error: Course IDs do not match.");
                System.out.println("Program terminates.");

                outFile.println("Data error: Course IDs do not match.");
                outFile.println("Program terminates.");

                group1.close();
                group2.close();
                outFile.close();

                return;
            }
            else                                                                // Step 7d
            {
                avg1 = calculateAverage(group1);                                // Step 7d i
                avg2 = calculateAverage(group2);                                // Step 7d ii
                printResult(outFile, courseId1, 1, avg1);                       // Step 7d iii
                printResult(outFile, courseId2, 2, avg2);                       // Step 7d iv
                avgGroup1 = avgGroup1 + avg1;                                   // Step 7d v
                avgGroup2 = avgGroup2 + avg2;                                   // Step 7d vi

                outFile.println();
                numberOfCourses++;                                              // Step 7d vii
            }
        } // end while

        if (group1.hasNext() && !group2.hasNext())                              // Step 8a
        {
            System.out.println("Ran out of data for group 2 before group 1.");
        }
        else if (!group1.hasNext() && group2.hasNext())                         // Step 8b
        {
            System.out.println("Ran out of data for group 1 before group 2.");
        }
        else                                                                    // Step 8c
        {
            outFile.printf("Average for group 1: %.2f %n", (avgGroup1 / numberOfCourses));
            outFile.printf("Average for group 2: %.2f %n", (avgGroup2 / numberOfCourses));
        }

        System.out.println("Done!");

        group1.close();
        group2.close();
        outFile.close();
    } // end main

    public static double calculateAverage(Scanner inp)
    {
        double totalScore = 0.0, courseAvg;
        int numberOfStudents = 0, score = 0;

        score = inp.nextInt();

        while (score != -999)
        {
            totalScore = totalScore + score;
            numberOfStudents++;
            score = inp.nextInt();
        } // end while

        courseAvg = totalScore / numberOfStudents;

        return courseAvg;
    } // end calculateAverage

    public static void printResult(PrintWriter outp, String courseId, int groupNo, double avg)
    {
        int noOfSymbols, count;

        if (groupNo == 1)
            outp.print(" " + courseId + " ");
        else
            outp.print("            ");
        noOfSymbols = (int)(avg) / 2;

        if (groupNo == 1)
            for (count = 0; count < noOfSymbols; count++)
                outp.print("*");
        else
            for (count = 0; count < noOfSymbols; count++)
                outp.print("#");
            
        outp.println();
    } // end printResult
}