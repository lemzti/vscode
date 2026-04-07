import javax.swing.JOptionPane;

public class MovieTicketSale {

    public static void main(String[] args) {

        // Input variables
        String ticketPriceInput, ticketSoldInput, donationInput;

        // Movie name
        String movieName = JOptionPane.showInputDialog("Enter movie name:");
        
        // Ticket prices
        ticketPriceInput = JOptionPane.showInputDialog("How much will adult tickets cost?");
        double adultTicketPrice = Double.parseDouble(ticketPriceInput);
        ticketPriceInput = JOptionPane.showInputDialog("How much will child tickets cost?");
        double childTicketPrice = Double.parseDouble(ticketPriceInput);

        // No. of tickets sold
        ticketSoldInput = JOptionPane.showInputDialog("How many adult tickets did we sell?");
        int adultTicketsSold = Integer.parseInt(ticketSoldInput);
        ticketSoldInput = JOptionPane.showInputDialog("How many child tickets did we sell?");
        int childTicketsSold = Integer.parseInt(ticketSoldInput);

        // Donation
        donationInput = JOptionPane.showInputDialog("Enter the % of money we will donate to charity:");
        double percentDonation = Double.parseDouble(donationInput);

        // Final calculations
        double grossAmount = (adultTicketPrice * adultTicketsSold) + (childTicketPrice * childTicketsSold);
        double amountDonated = grossAmount * percentDonation / 100.0;
        double netSale = grossAmount - amountDonated;

        String dataDisplay = String.format(
            "Movie Name: %s\n" +
            "Tickets Sold: %d\n" +
            "Gross Amount: $%.2f\n" +
            "Percentage of the Gross Amount donated: %.2f%%\n" +
            "Amount Donated: $%.2f\n" +
            "Net Sale:  $%.2f",
            movieName, adultTicketsSold + childTicketsSold, grossAmount, percentDonation, amountDonated, netSale
        );

        JOptionPane.showMessageDialog(
            null,
            dataDisplay,
            "Theater Sales Data",
            JOptionPane.INFORMATION_MESSAGE
        );
    }
}