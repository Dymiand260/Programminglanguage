/*Dymiand Webb 
  July 30, 2023
  In this assignment, You are asked to collaborate with Airgead Banking, 
  one of Chada Tech’s clients. Airgead Banking is well known in the community. 
  They often sponsor schools and have recently decided to partner with the local high school to 
  develop a program that will teach students the concepts of fiscal responsibility 
  (such as living within their means and spending less than they make) via an interactive system. 
  The initial focus for this project will be on investing and the power of compound interest. 
  You will develop an application that allows users to see how their investments will grow over time. 
  Airgead Banking has provided you with a list of functional requirements that describe what they need their 
  application to do.
*/


#include <iostream>
#include <iomanip>
using namespace std;

// Function to print the calculated results of each year's investment details
void printDetails(int year, double balance, double interestEarned) {
    // Print year, year-end balance, and interest earned with appropriate formatting
    cout << year << "\t$ " << balance << "\t$ " << interestEarned << endl;
}

// Function to calculate the end of year balance and interest earned
// for each year without additional monthly deposits
double calculateBalanceWithoutMonthlyDeposit(double principal, double interestRate, int years) {
    // Calculate the monthly interest rate
    double monthlyInterestRate = interestRate / 100 / 12;

    // Initialize the balance with the initial principal amount
    double balance = principal;

    // Loop through each year to calculate the balance and interest earned
    for (int year = 1; year <= years; year++) {
        double interestEarned = 0;

        // Loop through each month to compound the interest monthly
        for (int month = 1; month <= 12; month++) {
            interestEarned += balance * monthlyInterestRate;
            balance += balance * monthlyInterestRate;
        }

        // Call the printDetails function to print the results for the year
        printDetails(year, balance, interestEarned);
    }

    // Return the final calculated end of year balance
    return balance;
}

    // Function to calculate the end of year balance and interest earned
    // for each year with additional monthly deposits

    double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    // Calculate the monthly interest rate
    double monthlyInterestRate = interestRate / 100 / 12;

    // Initialize the balance with the initial investment amount
    double balance = initialInvestment;

    // Loop through each year to calculate the balance and interest earned
    for (int year = 1; year <= numberOfYears; year++) {
        double interestEarned = 0;

        // Loop through each month to compound the interest and add the monthly deposit
        for (int month = 1; month <= 12; month++) {
            balance += monthlyDeposit;
            interestEarned += balance * monthlyInterestRate;
            balance += balance * monthlyInterestRate;
        }

        // Call the printDetails function to print the results for the year
        printDetails(year, balance, interestEarned);
    }

    // Return the final calculated end of year balance
    return balance;
}

int main() {
    // Variables to store user input
    double principal, monthlyDeposit, interestRate;
    int years;

    // Collect input from the user
    cout << "Initial Investment Amount: $";
    cin >> principal;

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Annual Interest (%): ";
    cin >> interestRate;

    cout << "Number of Years: ";
    cin >> years;

    // Display the heading for the first investment scenario (without additional monthly deposits)
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;

    // Calculate and display the results for the first investment scenario
    double finalBalanceWithoutMonthlyDeposit = calculateBalanceWithoutMonthlyDeposit(principal, interestRate, years);
    cout << endl;

    // Display the heading for the second investment scenario (with additional monthly deposits)
    cout << "Balance and Interest With Additional $" << monthlyDeposit << " Monthly Deposits" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;

    // Calculate and display the results for the second investment scenario
    double finalBalanceWithMonthlyDeposit = balanceWithMonthlyDeposit(principal, monthlyDeposit, interestRate, years);
    cout << endl;

    return 0;
}
