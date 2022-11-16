#include "BankApp.h"
#include <iostream>
using namespace std;
BankApp::BankApp() {
    string choice;
    while (true){
        cout <<
        "Welcome to FCAI Banking Application\n"
        "0. to exit\n"
        "1. Create a New Account\n"
        "2. List Clients and Accounts\n"
        "3. Withdraw Money\n"
        "4. Deposit Money\n";
        cout << "Please Enter choice\n";
        cin >> choice;
        if(choice == "1")
            create_Account();
        else if(choice == "2")
            list();
        else if(choice == "3")
            withdraw();
        else if(choice == "4")
            deposit();
        else
            exit(0);

    }
}
void BankApp::create_Account() {
    id++;
    double balance, min_balance;
    Client temp;
    string name, Address, phone, choice;
    cout << "Please Enter Client Name" << endl;
    cin.clear();
    cin.sync();
    getline(cin, name);

    temp.set_name(name);
    cout << "Please Enter Client Address " << endl;
    getline(cin, Address);

    temp.set_Address(Address);
    cout << "Please Enter Client Phone" << endl;
    cin >> phone;
    temp.set_phone(phone);
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 " << endl;
    cin >> choice;
    if(choice == "1"){
        BankAccount acc;
        cout << "Please Enter the Starting Balance " << endl;
        cin >> balance;
        acc.set_balance(balance);
        string s = "FCAI-"+to_string(id);
        acc.set_account_id(s);
        temp.set_Account(acc, "1");
        v1.push_back(make_pair(temp, acc));

    } else{
        SavingsBankAccount acc;
        cout << "Please Enter the Starting Balance " << endl;
        cin >> balance;
        acc.set_balance(balance);
        cout << "Please Enter the minimum Balance " << endl;
        cin >> min_balance;
        acc.set_min_balance(min_balance);
        string s = "FCAI-"+to_string(id);
        acc.set_account_id(s);
        temp.set_Account(acc, "2");
        v2.push_back(make_pair(temp, acc));
    }
    cout<<"An account was created with ID "<< "FCAI-" + to_string(id) << " and Starting Balance "<< balance<<" L.E"<<endl;
}
void BankApp::list() {
    for(const auto &acc: v1){
        cout << "-------------------" << acc.first.get_name() << "--------------" << endl;
        cout << "Address: " << acc.first.get_Address() << " " << " Phone: " << acc.first.get_phone() << endl;
        cout << "Account ID: " << acc.second.get_account_id() << " (Basic) " << endl;
        cout << "Balance: " << acc.second.get_balance() << endl;
        cout << "\n\n";
    }
    for(const auto &acc: v2){
        cout << "-------------------" << acc.first.get_name() << "--------------" << endl;
        cout << "Address: " << acc.first.get_Address() << " " << " Phone: " << acc.first.get_phone() << endl;
        cout << "Account ID: " << acc.second.get_account_id() << " (Savings) " << endl;
        cout << "Balance: " << acc.second.get_balance() << endl;
        cout << "Minimum balance: " << acc.second.get_min_balance() << endl;
        cout << "\n\n";
    }
}
void BankApp::withdraw() {
    string ID;
    double amount;
    cout << "Please Enter Account ID (e.g., FCAI-015) " << endl;
    cin >> ID;

    for(auto &acc: v1){
        if(ID == acc.second.get_account_id()){
            cout << "Account ID: " << acc.second.get_account_id() << endl;
            cout << "Account Type: " << "Basic " << endl;
            cout << "Balance: " << acc.second.get_balance() << endl;
            Maram:
            cout << "Please Enter The Amount to Withdraw " << endl;
            cin >> amount;
            while (!acc.second.withdraw(amount)){
                cout << "Sorry. This is more than what you can withdraw." << endl;
                goto Maram;
            }
            cout << "Thank you." << endl;
            cout << "Account ID: " << acc.second.get_account_id() << endl;
            cout << "New Balance: " << acc.second.get_balance() << endl;
        }
    }
    for( auto &acc: v2) {
        if (ID == acc.second.get_account_id()) {
            cout << "Account ID: " << acc.second.get_account_id() << endl;
            cout << "Account Type: " << "Savings " << endl;
            cout << "Balance: " << acc.second.get_balance() << endl;
            Ahmed:
            cout << "Please Enter The Amount to Withdraw " << endl;
            cin >> amount;
            while (!acc.second.withdraw(amount)) {
                cout << "Sorry. This is more than what you can withdraw." << endl;
                goto Ahmed;
            }
            cout << "Thank you." << endl;
            cout << "Account ID: " << acc.second.get_account_id() << endl;
            cout << "New Balance: " << acc.second.get_balance() << endl;
        }
    }
}
void BankApp::deposit() {
    string ID;
    double amount;
    cout << "Please Enter Account ID (e.g., FCAI-015) " << endl;
    cin >> ID;

    for (auto &acc: v1) {
        if (ID == acc.second.get_account_id()) {
            cout << "Account ID: " << acc.second.get_account_id() << endl;
            cout << "Account Type: " << "Basic " << endl;
            cout << "Balance: " << acc.second.get_balance() << endl;
            cout << "Please Enter The Amount to Deposit " << endl;
            cin >> amount;
            acc.second.deposit(amount);
            cout << "Thank you." << endl;
            cout << "Account ID: " << acc.second.get_account_id() << endl;
            cout << "New Balance: " << acc.second.get_balance() << endl;
        }
    }
    for (auto &acc: v2) {
        if (ID == acc.second.get_account_id()) {
            cout << "Account ID: " << acc.second.get_account_id() << endl;
            cout << "Account Type: " << "Savings " << endl;
            cout << "Balance: " << acc.second.get_balance() << endl;
            Begin:
            cout << "Please Enter The Amount to Deposit " << endl;
            cin >> amount;
            while (!acc.second.deposit(amount)) {
                cout << "Sorry. The amount is less than 100 " << endl;
                goto Begin;
            }
            cout << "Thank you." << endl;
            cout << "Account ID: " << acc.second.get_account_id() << endl;
            cout << "New Balance: " << acc.second.get_balance() << endl;
        }
    }
}


