#include "Investment.h"

// Constructor
Investment::Investment(double initInvest, double monthDeposit, double annualInterest, int numYears)
    : initialInvestment(initInvest), monthlyDeposit(monthDeposit), annualInterestRate(annualInterest), numberOfYears(numYears) {}

// Function to display report without monthly deposits
void Investment::displayReportWithoutMonthlyDeposits() const {
    double balance = initialInvestment;
    double yearEndInterest;

    std::cout << "\nReport without Monthly Deposits:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Year\tYear End Balance\tYear End Earned Interest\n";
    std::cout << "--------------------------------------------------\n";

    for (int year = 1; year <= numberOfYears; ++year) {
        yearEndInterest = 0;
        for (int month = 1; month <= 12; ++month) {
            double interest = balance * (annualInterestRate / 100) / 12;
            balance += interest;
            yearEndInterest += interest;
        }
        std::cout << year << "\t" << balance << "\t\t" << yearEndInterest << "\n";
    }
}

// Function to display report with monthly deposits
void Investment::displayReportWithMonthlyDeposits() const {
    double balance = initialInvestment;
    double yearEndInterest;

    std::cout << "\nReport with Monthly Deposits:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Year\tYear End Balance\tYear End Earned Interest\n";
    std::cout << "--------------------------------------------------\n";

    for (int year = 1; year <= numberOfYears; ++year) {
        yearEndInterest = 0;
        for (int month = 1; month <= 12; ++month) {
            balance += monthlyDeposit;
            double interest = balance * (annualInterestRate / 100) / 12;
            balance += interest;
            yearEndInterest += interest;
        }
        std::cout << year << "\t" << balance << "\t\t" << yearEndInterest << "\n";
    }
}
