#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>

class Account
{
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate() { return 4.0; };
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; };
};
double Account::interestRate = initRate();


#endif  