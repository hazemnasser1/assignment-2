
#ifndef BANK_SAVINGSBANKACCOUNT_H
#define BANK_SAVINGSBANKACCOUNT_H
#include "BankAccount.h"

class SavingsBankAccount: public BankAccount{
protected:
    double min_balance;
public:
    SavingsBankAccount() = default;
    SavingsBankAccount(double balance_val, double min_balance_val = 1000.0);
    double get_min_balance()const;
    void set_min_balance(double min_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
};



#endif //BANK_SAVINGSBANKACCOUNT_H
