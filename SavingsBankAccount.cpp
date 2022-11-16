#include "SavingsBankAccount.h"
#include <iostream>

SavingsBankAccount::SavingsBankAccount(double balance_val, double min_balance_val){
    if(balance_val < min_balance_val){
        std::cout << "Invalid balance " << std::endl;
    }
    else{
        balance = balance_val;
        min_balance = min_balance_val;
    }
}

double SavingsBankAccount::get_min_balance() const {
    return min_balance;
}

void SavingsBankAccount::set_min_balance(double min_balance) {
    this->min_balance = min_balance;
}
bool SavingsBankAccount::withdraw(double amount) {
    if(amount >= min_balance){
        return BankAccount::withdraw(amount);
     } else{
        return false;
     }
}
bool SavingsBankAccount::deposit(double amount) {
    if(amount >= 100.0){
        BankAccount::deposit(amount);
        return true;
    } else{
        return false;
    }
}
