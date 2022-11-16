#include "BankAccount.h"
BankAccount::BankAccount()
        : balance{0.0}{}
BankAccount::BankAccount(double balance)
        : balance{balance}{}

bool BankAccount::withdraw(double amount) {
    if(amount > balance){
        return false;
    } else{
        balance -= amount;
        return true;
    }
}

bool BankAccount::deposit(double amount) {
    balance += amount;
    return true;
}

void BankAccount::set_account_id(std::string account_id) {
    this->account_id = account_id;
}

std::string BankAccount::get_account_id() const {
    return this->account_id;
}

void BankAccount::set_balance(double balance) {
    this->balance = balance;
}

double BankAccount::get_balance()const  {

    return this-> balance;
}