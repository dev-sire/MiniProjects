import java.util.HashMap;
import java.util.Scanner;

public class CurrencyConverter {

    @SuppressWarnings("resource")
    public static void main(String[] args) {
        // Exchange rates (modify these as needed)
        HashMap<String, Double> exchangeRates = new HashMap<>();
        exchangeRates.put("USD", 1.0); // 1 USD is 1 USD (baseline)
        exchangeRates.put("PKR", 223.0); // 1 USD is approximately 223 PKR
        exchangeRates.put("EUR", 0.92); // 1 USD is approximately 0.92 EUR

        Scanner scanner = new Scanner(System.in);

        // Get user input for currency conversion
        System.out.println("Welcome to the Currency Converter!");
        System.out.println("Available currencies: USD, PKR, EUR");
        System.out.print("Enter the currency you have (from): ");
        String fromCurrency = scanner.nextLine().toUpperCase(); // Convert input to uppercase

        System.out.print("Enter the amount you have: ");
        double amount = scanner.nextDouble();
        
        scanner.nextLine();
        System.out.print("Enter the currency you want to convert to (to): ");
        String toCurrency = scanner.nextLine().toUpperCase(); // Convert input to uppercase

        // Check for valid currencies
        if (!exchangeRates.containsKey(fromCurrency) || !exchangeRates.containsKey(toCurrency)) {
            System.out.println("Invalid currency entered. Please try again.");
            return;
        }

        // Perform conversion
        double conversionRate = exchangeRates.get(toCurrency) / exchangeRates.get(fromCurrency);
        double convertedAmount = amount * conversionRate;

        // Display result
        System.out.printf("%.2f %s is equal to %.2f %s\n", amount, fromCurrency, convertedAmount, toCurrency);

        scanner.close();
    }
}
