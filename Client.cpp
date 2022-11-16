#include "Client.h"

void Client::set_name(std::string name) {
    this->name = name;
}
std::string Client::get_name()const {return this->name; }

void Client::set_phone(std::string phone) {
    this->phone = phone;
}

std::string Client::get_phone()const {return this->phone; }

void Client::set_Address(std::string Address) {
    this->Address = Address;
}
std::string Client::get_Address()const {return this->Address; }

void Client::set_Account(BankAccount &acc, std::string choice) {
    if(choice == "1"){

        Account = new BankAccount;
        Account->set_balance(acc.get_balance());
        Account->set_account_id(acc.get_account_id());

    } else{
        Account = new SavingsBankAccount;
        Account->set_balance(acc.get_balance());
        Account->set_account_id(acc.get_account_id());
        Account->set_min_balance(acc.get_min_balance());
    }
}

























