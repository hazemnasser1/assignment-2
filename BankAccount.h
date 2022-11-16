//
// Created by lenovo on 10/11/2022.
//

#ifndef BANK_BANKACCOUNT_H
#define BANK_BANKACCOUNT_H
#include "string"

class BankAccount {
protected:

    std::string account_id;
    double balance;
public:

    BankAccount();
    BankAccount(double balance);
    virtual bool withdraw(double amount);
    virtual double get_min_balance(){};
    virtual void set_min_balance(double min_balance){};
    virtual bool deposit(double amount);
    void set_account_id(std::string account_id);
    std::string get_account_id()const;
    void set_balance(double balance);
    double get_balance()const;

};


#endif //BANK_BANKACCOUNT_H
