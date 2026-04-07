// Program to determine absolute value of an integer

import javax.swing.JOptionPane;

public class AbsoluteValue {

    public static void main(String[] args) {

        int number, temp;
        String numString;

        numString = JOptionPane.showInputDialog("Enter an integer:");   // Line 1
        number = Integer.parseInt(numString);                           // Line 2
        temp = number;                                                  // Line 3

        if (number < 0) {                                               // Line 4
            number = -number;                                           // Line 5
        }

        JOptionPane.showMessageDialog(                                  // Line 6
            null,
            "The absolute value of " + temp + " is " + number + ".",
            "Absolute Value",
            JOptionPane.INFORMATION_MESSAGE
        );

        System.exit(0);
    }
}
