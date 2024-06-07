#include <iostream>
#include "Investment.h"

int main() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int numberOfYears;
    char userResponse;

    do {
        // Input section
        std::cout << "Enter Initial Investment Amount: ";
        std::cin >> initialInvestment;

        std::cout << "Enter Monthly Deposit: ";
        std::cin >> monthlyDeposit;

        std::cout << "Enter Annual Interest Rate (in %): ";
        std::cin >> annualInterestRate;

        std::cout << "Enter Number of Years: ";
        std::cin >> numberOfYears;

        // Create Investment object
        Investment investment(initialInvestment, monthlyDeposit, annualInterestRate, numberOfYears);

        // Prompt to continue and display reports
        std::cout << "Press any key to continue...";
        std::cin.ignore();
        std::cin.get();

        // Display reports
        investment.displayReportWithoutMonthlyDeposits();
        investment.displayReportWithMonthlyDeposits();

        // Prompt user to test different parameters
        std::cout << "\nDo you want to test different parameters? (yes/no): ";
        std::cin >> userResponse;

    } while (userResponse == 'y' || userResponse == 'Y');

    return 0;
}
