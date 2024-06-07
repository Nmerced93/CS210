// Neomi Merced - 6/6/2024 - CS210 Project Two

#pragma once
#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
#include <iomanip>

class Investment {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int numberOfYears;

public:
    // Constructor
    Investment(double initInvest, double monthDeposit, double annualInterest, int numYears);

    // Function to display report without monthly deposits
    void displayReportWithoutMonthlyDeposits() const;

    // Function to display report with monthly deposits
    void displayReportWithMonthlyDeposits() const;
};

#endif
