
#ifndef BANK_CLIENT_H
#define BANK_CLIENT_H
#include "SavingsBankAccount.h"

class Client {
private:
    BankAccount* Account;
    std::string name;
    std::string phone;
    std::string Address;
public:
    void set_Account(BankAccount &acc, std::string choice);
    void set_name(std::string name);
    void set_phone(std::string phone);
    void set_Address(std::string Address);
    void get_Account(const BankAccount &acc);
    std::string get_name()const;
    std::string get_phone()const;
    std::string get_Address()const;
};



#endif //BANK_CLIENT_H
