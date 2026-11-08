#include "BankAccount.hpp"
#include "BankRegistry.hpp"

//  Ordinea din lista respecta ordinea declaratiei din header: iban -> initialDeposit -> balance.
BankAccount::BankAccount(const std::string& accountIban, double deposit)
    : iban(accountIban), 
      initialDeposit(deposit), 
      balance(initialDeposit) //    initialDeposit a fost declarat si initializat inainte
{
    //  Singleton
    BankRegistry::getInstance().logRegistration(iban);
    std::cout << "[BankAccount] Creat contul " << iban << " cu balanta: " << balance << " RON\n";
}

BankAccount::~BankAccount() {
    std::cout << "[BankAccount] Inchidere cont " << iban << "\n";
}

void BankAccount::printInfo() const {
    std::cout << "Cont: " << iban << " | Balanta disponibila: " << balance << " RON\n";
}