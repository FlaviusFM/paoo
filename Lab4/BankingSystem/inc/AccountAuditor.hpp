#ifndef ACCOUNT_AUDITOR_HPP
#define ACCOUNT_AUDITOR_HPP

#include "BankAccount.hpp"
#include <iostream>
#include <cstdint>

class AccountAuditor {
private:
    //  Prezenta unei referinte si a unui membru const face ca
    //  C++ sa stearga automat operatorul de atribuire operator=
    BankAccount& targetAccount;
    const uint64_t auditorId;

public:
    AccountAuditor(BankAccount& account, uint64_t id)
        : targetAccount(account), auditorId(id) {}


    void inspect() const {
        std::cout << "[Auditor #" << auditorId << "] Inspecteaza -> ";
        targetAccount.printInfo();
    }
};

#endif