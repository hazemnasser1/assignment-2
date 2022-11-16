
#ifndef BANK_BANKAPP_H
#define BANK_BANKAPP_H


#include "SavingsBankAccount.h"
#include "BankAccount.h"
#include "Client.h"
#include <string>
#include <vector>
using namespace std;

class BankApp {
private:
    int id{0};
    vector<pair<Client, BankAccount>> v1;
    vector<pair<Client, SavingsBankAccount>> v2;
public:
    BankApp();
    void create_Account();
    void list();
    void withdraw();
    void deposit();
};


#endif //BANK_BANKAPP_H
