import java.util.*;

public class CableCompanyBilling {

    static Scanner input = new Scanner(System.in);

    // Named constants - Residential Customers
    static final double R_BILL_PROC_FEE = 4.50;
    static final double R_BASIC_SERV_COST = 20.50;
    static final double R_COST_PREM_CHANNEL = 7.50;

    // Named constants - Business Customers
    static final double B_BILL_PROC_FEE = 15.00;
    static final double B_BASIC_SERV_COST = 75.00;
    static final double B_BASIC_CONN_COST = 5.00;
    static final double B_COST_PREM_CHANNEL = 50.50;
    
    public static void main(String[] args) {
        
        // Variable declaration
        int accountNumber, noOfPremChannels, noOfBasicServConn;
        double amountDue;
        char customerType;

        System.out.println("This program computes a cable bill.");

        System.out.print("Enter the account number: ");                     // Step 1
        accountNumber = input.nextInt();                                        // Step 2
        System.out.println();

        System.out.print("Enter the customer type "
                        + "(R/r for Residental, "
                        + "B/b for Business): ");                               // Step 3
        customerType = input.next().charAt(0);                            // Step 4
        System.out.println();

        switch (customerType) {
            case 'R':                                                           // Step 5
            case 'r':
                System.out.print("Enter the number of "
                                + "premium channels: ");                        // Step 5a
                noOfPremChannels = input.nextInt();                             // Step 5b
                System.out.println();

                amountDue = R_BILL_PROC_FEE + R_BASIC_SERV_COST +
                            (noOfPremChannels * R_COST_PREM_CHANNEL);           // Step 5c

                System.out.println("Account number = " + accountNumber);        //  Step 5d
                System.out.printf("Amount due = $%.2f %n", amountDue);         // Step 5e
                break;
            
            case 'B':                                                           // Step 6
            case 'b':
                System.out.print("Enter the number of "
                                + "basic service connections: ");               // Step 6a
                noOfBasicServConn = input.nextInt();                            // Step 6b
                System.out.println();

                System.out.print("Enter the number of "
                                + "premium channels: ");                        // Step 6c
                noOfPremChannels = input.nextInt();                             // Step 6d
                System.out.println();

                if (noOfBasicServConn <= 10) {                                  // Step 6e
                    amountDue = B_BILL_PROC_FEE + B_BASIC_SERV_COST +
                                (noOfPremChannels * B_COST_PREM_CHANNEL) ; 
                } else {
                    amountDue = B_BILL_PROC_FEE + B_BASIC_SERV_COST +
                                ((noOfBasicServConn - 10) * B_BASIC_CONN_COST) +
                                (noOfPremChannels * B_COST_PREM_CHANNEL);
                }

                System.out.println("Account number = " + accountNumber);        //  Step 6f
                System.out.printf("Amount due = $%.2f %n", amountDue);         // Step 6g
                break;
            
            default:                                                            // Step 7
                System.out.println("Invalid customer type.");
        }
    }
}
