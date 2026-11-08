#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

#include <string>
#include <iostream>

class BankAccount {
private:
    const std::string iban;   //    Membru const: TREBUIE initializat in lista de initializare
    double initialDeposit;    //    Declarat INAINTE de balance
    double balance;           //    Depinde de initialDeposit

public:
    BankAccount(const std::string& accountIban, double deposit);

    ~BankAccount();

    //  Contul bancar este unic. Interzicem copierea direct la nivel de compilator.
    BankAccount(const BankAccount&) = delete;            //     Fara copy constructor
    BankAccount& operator=(const BankAccount&) = delete; //     Fara copy assignment

    void printInfo() const;
    std::string getIban() const { return iban; }
    double getBalance() const { return balance; }
};

#endif